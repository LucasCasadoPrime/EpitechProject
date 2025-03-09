import '@/app/ui/global.css';
import { inter } from '@/app/ui/fonts';
import React from "react";
import NavBar from "@/app/navbar";
import Footer from "@/app/footer";

export default function RootLayout({
  children,
}: {
  children: React.ReactNode;
}) {
  return (
    <html lang="fr">
      <body className={`${inter.className} antialiased`}>
        <NavBar />
        <main className="flex-1 overflow-y-auto h-[calc(100vh-200px)]"> {children} </main>
        <Footer />
      </body>
    </html>
  );
}
