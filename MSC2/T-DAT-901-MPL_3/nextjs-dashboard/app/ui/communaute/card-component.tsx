'use client';
import { useEffect, useState } from 'react';

interface ImageComponentProps {
    scale?: number; // Facteur de grossissement (par exemple : 1.5 pour 150%)
}

const ImageComponent: React.FC<ImageComponentProps> = ({ scale = 1 }) => {
    const [imageUrl, setImageUrl] = useState<string | null>(null);

    useEffect(() => {
        const fetchImage = async () => {
            try {
                const response = await fetch(
                    'https://cards.scryfall.io/small/front/b/d/bd8fa327-dd41-4737-8f19-2cf5eb1f7cdd.jpg?1614638838'
                );
                const blob = await response.blob();
                const imageObjectURL = URL.createObjectURL(blob);
                setImageUrl(imageObjectURL);
            } catch (error) {
                console.error('Error fetching the image:', error);
            }
        };

        fetchImage();
    }, []);

    if (!imageUrl) {
        return <p>Loading...</p>;
    }

    return (
        <img
            src={imageUrl}
            alt="Fetched Image"
            style={{
                transform: `scale(${scale})`, // Applique le facteur de grossissement
                transformOrigin: 'center', // Centre la transformation
            }}
            className="object-cover"
        />
    );
};

export default ImageComponent;
