export default function Layout() {
    return (
        <div className="flex flex-col h-[calc(100vh-200px)]">
            <div className="flex h-screen">
                <div className="w-1/4 bg-gray-100 border-r p-4">
                    <h2 className="font-bold mb-4">Discussions</h2>
                    <ul>
                        <li className="mb-2">Deck 1</li>
                        <li>Deck 2</li>
                    </ul>
                </div>
                <div className="flex-1 flex flex-col justify-end p-4">
                    <div className="flex justify-between  mb-4">
                        <input
                            type="text"
                            placeholder="Deck à analyser ..."
                            className="flex-1 border rounded p-2"
                        />
                        <button className="bg-gray-800 text-white px-4 py-2 rounded-lg ml-2">Deck</button>
                        <button className="bg-gray-800 text-white px-4 py-2 rounded-lg ml-2">Chercher</button>
                    </div>
                </div>
            </div>
        </div>
    );
}
