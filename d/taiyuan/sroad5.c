// /d/taiyuan/nroad1.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "ɽ��");
	set("long", @LONG
��˳�Ŵ������ǰ�ߣ��������߽���ɽ���·Ҳ��ʼ������ƽ��
������·˳��ɽ��������ǰ���죬���߶���ï�ܵ����֣�ż����������
����������С�	
LONG
        );
set("outdoors", "taiyuan");
set("valid_startroom", 1);
set("exits", ([
                "southwest":__DIR__"sroad4", 
///                "northup":"/d/hengshan/daziling", 
                
	]));
       setup();
	replace_program(ROOM);
}
