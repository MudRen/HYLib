// baling/edao1
// Room in ����
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һƬ�������п��ٵ�һ�յء���������ϡ�٣������Ե�ʮ��
�ľ����ߴ��������ס�˴��۵����⣬Ϊ�����ṩ��һ����Ȼ����Ϣ��
����
LONG
	);

	set("exits", ([
                "northup" : __DIR__"shanyanan",
                "south" : __DIR__"shulin1",
	]));

 
        set("objects", ([
		__DIR__"npc/she" : 4
	]));
	set("outdoors", "yuyang");
	setup();
	replace_program(ROOM);
}


