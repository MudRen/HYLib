// /d/taiyuan/nroad3.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;
void create()
{
	set("short", "��ٵ�");
	set("long", @LONG
������һ����������Ĵ�ٵ��ϡ��˴�����Ⱥϡ�١�������Ǵ��
ԭ�ˡ�
LONG
        );
set("outdoors", "mayi");
set("valid_startroom", 1);
set("exits", ([
                "southeast":"/d/taiyuan/nroad3",
                "northup":__DIR__"changcheng9",

	]));
       setup();
	replace_program(ROOM);
}
