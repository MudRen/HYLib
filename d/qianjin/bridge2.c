inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
�ɻ����ɺ�«״���ڴ�һ�������������������ƻ�żפ��Զ���ƻ���㣬������Ӱ
ө�⣬�����ѱ档����ʱ��˪����𣬷��ֽ�Ⱦ�Ʊ̣�Ұ��˥��ܽ�أ���ӳˮ�ʣ�«έ
�к���Ⱥ������߿���ƣ��������ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"grassroom",
  "west" : __DIR__"lastbridge",
]));
	set("outdoors","fengyun");
        set("coor/x",-110);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
