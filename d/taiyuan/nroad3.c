// /d/taiyuan/nroad3.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "��ٵ�");
	set("long", @LONG
������һ����������Ĵ�ٵ��ϡ��˴�����Ⱥϡ�١�����쵽���
ԭ�ˡ�
LONG
        );
set("outdoors", "taiyuan");
set("valid_startroom", 1);
set("exits", ([
                "north":"/d/heimuya/pingdingzhou", 
                "northwest":"/d/mayi/sroad", 	
                "south":__DIR__"nroad2", 
                
	]));
       setup();
	replace_program(ROOM);
}
