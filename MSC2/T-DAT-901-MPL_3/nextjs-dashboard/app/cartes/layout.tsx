export default function Layout({ children }: { children: React.ReactNode }) {
  return (
    <div className="flex flex-col h-[calc(100vh-200px)]">
      <main className="flex-1 overflow-y-auto p-6">{children}</main>
    </div>
  );
}