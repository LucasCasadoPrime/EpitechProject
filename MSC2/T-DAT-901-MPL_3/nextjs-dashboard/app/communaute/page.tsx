import Search from "@/app/ui/search";
import { Button } from "@/app/ui/button";
import ImagePage from "@/app/ui/communaute/card-component";

export default async function Page() {
    const numImages = 3; // Nombre d'images par section

    return (
        <main className="m-5">
            {/* Section STANDARD */}
            <section className="my-10">
                <h2 className="text-2xl font-bold mb-4">STANDARD</h2>
                <hr className="border-t-2 border-black w-full mb-12" />
                <div className="flex items-center justify-between">
                    {/* Images */}
                    <div className="grid grid-cols-3 gap-4 w-full">
                        {Array.from({ length: numImages }).map((_, index) => (
                            <div
                                key={`standard-${index}`}
                                className="flex justify-center items-center"
                            >
                                <ImagePage scale={1.20}/>
                            </div>
                        ))}
                    </div>
                    {/* Bouton "+" */}
                    <button
                        className="ml-4 w-16 h-16 pb-1 flex items-center justify-center rounded-full text-5xl font-bold hover:bg-gray-200"
                        aria-label="Add"
                    >
                        +
                    </button>
                </div>
            </section>

            {/* Section COMMANDER */}
            <section className="my-10">
                <h2 className="text-2xl font-bold mb-4">COMMANDER</h2>
                <hr className="border-t-2 border-black w-full mb-12" />
                <div className="flex items-center justify-between">
                    {/* Images */}
                    <div className="grid grid-cols-3 gap-4 w-full">
                        {Array.from({ length: numImages }).map((_, index) => (
                            <div
                                key={`commander-${index}`}
                                className="flex justify-center items-center"
                            >
                                <ImagePage scale={1.20}/>
                            </div>
                        ))}
                    </div>
                    {/* Bouton "+" */}
                    <button
                        className="ml-4 w-16 h-16 pb-1 flex items-center justify-center rounded-full text-5xl font-bold hover:bg-gray-200"
                        aria-label="Add"
                    >
                        +
                    </button>
                </div>
            </section>
        </main>
    );
}
