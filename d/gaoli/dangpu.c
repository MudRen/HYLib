// /d/gaoli/dangpu
// Room in ����
inherit ROOM;
void create()	
{
        set("short", "��������");
	set("long", @LONG
���߽��˸����ĵ��̣��������ֻ谵����ǰ�޴�Ĺ�̨����ָ��ϸ
��������Χ�ţ�һ��С�Ľ�����ģ�����ϰ��Ǹ��ܾ����������ˣ�����
���˽������ܿ����غ��㺮�ѣ����۾���ȴû��ʲôЦ�⣬�������ش�
�����㡣
LONG
          );
set("exits", ([
                "west":__DIR__"zhuque-2",    
	]));
 set("objects", ([
		"/d/gaoli/npc/jin1" : 1,
	]));
       setup();
	replace_program(ROOM);
}
