inherit ROOM;
void create()
{
        set("short", "�����ۼװ�");
        set("long", @LONG
��ɫ���̣���ɫ������΢���������羰���ˡ�һ������ȭ�о��������Ů�˵�
��Ц����ʱ�ĴӴ����д���������ϸ�����������ƺ��������ŵ͵͵ı���֮�����봬
�ϵĻ���Ц�Ｋ����Ǣ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"boat2",
  "south" : __DIR__"tading",
]));
	set("outdoors","fengyun");
        set("coor/x",-150);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
