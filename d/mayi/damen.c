// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
����һ����լԺ����֪������ס����ʲô�ˡ�ƽʱ����������ǹ�
�ŵģ�Ҳ������ʲô�˴�������롣
LONG
	);
set("outdoors", "mayi");
set("exits", ([
                "south": __DIR__"xijie", 
         ]));
       setup();
	replace_program(ROOM);
}	
