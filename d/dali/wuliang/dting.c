// Room: dting.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "����");
	set("long", @LONG
�����ǹ����������Ŀ�����Ϣ֮�ã�һӦ���߱�������һ��ƽ���Ų���
���ʣ�ǽ�Ϲ��ż���ɽˮ������������͸�������������ֱ�������
LONG
	);
	set("exits", ([ 
	    "west" : __DIR__"wlj",	    
        ]));

	setup();
        replace_program(ROOM);
}
