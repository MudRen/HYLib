
inherit ROOM;


void create()
{
	set("short", "��Ժ");
	set("long", @LONG
���Ǽ���ʦ�ҵĺ�Ժ������ǰԺ����������������ˡ�ֻ���൱��
��ݵ��������п��ܰ����뵽���
LONG);
	
	set("exits", ([
                "northwest" : __DIR__"tingyuan",
                "east":__DIR__"huayuan",
	]));
    
	set("outdoors", "yuyang");
	setup();
	replace_program(ROOM);
}
