inherit ROOM;
void create()
{
        set("short", "ʯͷ�Ͻ�");
        set("long", @LONG
�����������ڵ�ʯͷ�Ͻ֡�������������ȥ���ǳ�������ţ�����Щ�͵�
�˷����ضΡ����Ҷ���ƽ��ס�ң����պ���ϲϲЦЦ������ǧ�ҵƻ�
LONG );
        set("exits", ([
                "north" : __DIR__"stnanjie2",
        	"south" : __DIR__"nanmen",
		"west" : __DIR__"mingju",
		"east" : __DIR__"mingju1",
	]));
	set("outdoors", "����");
	setup();
}
