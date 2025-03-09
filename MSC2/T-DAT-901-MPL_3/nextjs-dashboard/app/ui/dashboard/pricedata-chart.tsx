"use client";

import { CardPrice } from "@/app/lib/definitions";
import { format } from "date-fns";
import { Axis, LineSeries, Grid, XYChart, Tooltip } from "@visx/xychart";

export default function PriceDataChart({
  CardPrice,
}: {
  CardPrice: CardPrice[];
}) {
  if (!CardPrice || CardPrice.length === 0) {
    return <p className="mt-4 text-gray-400">Choose a card.</p>;
  }

  const accessors = {
    xAccessor: (d: CardPrice) => format(d.date, "hh:mm:ss"),
    yAccessor: (d: CardPrice) => d.price,
  };

  return (
    <XYChart
      width={1000}
      height={400}
      xScale={{ type: "band" }}
      yScale={{ type: "linear" }}
    >
      <Axis orientation="bottom" numTicks={5} />
      <Axis orientation="left" numTicks={5} label="Prix (€)" />
      <Grid columns={true} numTicks={10} />
      <LineSeries dataKey="Card Price" data={CardPrice} {...accessors} />
      <Tooltip
        snapTooltipToDatumX
        snapTooltipToDatumY
        showVerticalCrosshair
        showSeriesGlyphs
        renderTooltip={({ tooltipData, colorScale }) =>
          tooltipData?.nearestDatum ? (
            <div>
              <div
                style={{ color: colorScale?.(tooltipData.nearestDatum.key) }}
              >
                {tooltipData.nearestDatum.key}
              </div>
              {accessors.yAccessor(tooltipData.nearestDatum.datum as CardPrice)}
              {" €"}
            </div>
          ) : (
            <div>No data available</div>
          )
        }
      />
    </XYChart>
  );
}
