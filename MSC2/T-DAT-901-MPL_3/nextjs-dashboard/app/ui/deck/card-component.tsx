"use client";
import { useEffect, useState } from "react";

export default function CardComponent({ link }: { link: string }) {
  const [imageSrc, setImageSrc] = useState<string | null>(null);

  useEffect(() => {
    async function fetchImage() {
      try {
        const response = await fetch(link);
        const imageBlob = await response.blob();
        const imageObjectURL = URL.createObjectURL(imageBlob);
        setImageSrc(imageObjectURL);
      } catch (error) {
        console.error("Failed to fetch image:", error);
      }
    }

    fetchImage();
  }, [link]);

  return (
    <div>
      {imageSrc ? (
        <img src={imageSrc} alt="Fetched content" />
      ) : (
        <p>Loading...</p>
      )}
    </div>
  );
}
