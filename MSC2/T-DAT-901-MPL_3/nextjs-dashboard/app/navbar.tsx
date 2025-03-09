// components/NavBar.js
import Link from 'next/link';

export default function NavBar() {
  return (
    <div className="flex w-full items-center justify-between bg-white px-8 py-4 shadow-md">
      {/* Logo */}
      <div className="flex items-center">
        <img src="/logo.png" alt="logo" className="w-15 h-12" />
      </div>

      {/* Links */}
      <div className="flex items-center space-x-6">
        <Link href="/cartes" className="text-gray-700 hover:bg-gray-200 rounded-md px-4 py-2">Cartes</Link>
        <Link href="/decks" className="text-gray-700 hover:bg-gray-200 rounded-md px-4 py-2">Decks</Link>
        <Link href="/analyse" className="text-gray-700 hover:bg-gray-200 rounded-md px-4 py-2">Analyse</Link>
        <Link href="/communaute" className="text-gray-700 hover:bg-gray-200 rounded-md px-4 py-2">Communauté</Link>

      {/* Sign In and Register Buttons */}
        <Link href="/signin" className="border border-gray-400 px-4 py-2 rounded-md text-gray-700 hover:bg-gray-200">Se connecter</Link>
        <Link href="/register" className="bg-gray-800 text-white px-4 py-2 rounded-md hover:bg-gray-700">S'inscrire</Link>
    </div>
  </div>
  );
}
