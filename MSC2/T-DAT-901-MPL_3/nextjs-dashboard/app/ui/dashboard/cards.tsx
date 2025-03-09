import {
  InboxIcon,
  BookOpenIcon,
  RectangleGroupIcon,
  GlobeEuropeAfricaIcon,
} from "@heroicons/react/24/outline";

const iconMap = {
  vintage: BookOpenIcon,
  legacy: GlobeEuropeAfricaIcon,
  pioneer: RectangleGroupIcon,
  modern: InboxIcon,
};

export default async function CardWrapper() {
  return (
    <>
      <Card title="Vintage" type="vintage" />
      <Card title="Legacy" type="legacy" />
      <Card title="Pioneer" type="pioneer" />
      <Card title="Modern" type="modern" />
    </>
  );
}

export function Card({
  title,
  type,
}: {
  title: string;
  type: "vintage" | "legacy" | "pioneer" | "modern";
}) {
  const Icon = iconMap[type];

  return (
    <div className="rounded-xl bg-gray-50 p-2 shadow-sm">
      <div className="flex p-4">
        {Icon ? <Icon className="h-5 w-5 text-gray-700" /> : null}
        <h3 className="ml-2 text-sm font-medium">{title}</h3>
      </div>
    </div>
  );
}
