// components/Footer.js
import Link from 'next/link';

export default function Footer() {
  return (
    <footer className="bg-gray-200 text-gray-800 py-6">
      <div className="container mx-auto px-8">
        <div className="flex flex-col md:flex-row items-center justify-between">
          
          {/* Contact Section */}
          <div className="mb-4 md:mb-0">
            <h2 className="font-semibold">Contact</h2>
            <p>0612121212</p>
            <p><a href="mailto:contactc@gmail.com">contactc@gmail.com</a></p>
          </div>

          {/* Shops Section */}
          <div className="mb-4 md:mb-0">
            <h2 className="font-semibold">Shops</h2>
            <p><Link href="https://www.magic-ville.com">Magic-ville</Link></p>
            <p><Link href="https://www.cardmarket.com">Card market</Link></p>
          </div>

          {/* Administrative Section */}
          <div>
            <h2 className="font-semibold">Administratif</h2>
            <p><Link href="/mentions-legales">Mentions légales</Link></p>
          </div>
        </div>
      </div>
    </footer>
  );
}
