// Room: /d/cangzhou/beijie1.c

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���ݳǱ��֣����صĺ�����Ű�Ĵ���·�ϼ���һ�����˶�û�С��ߵ�����
�㲻���������·���·��������һ�����У�����ܶ�๤���������ػصİ���
�״���
LONG );
        set("exits", ([
                "north" : __DIR__"beimen",
        	"south" : __DIR__"beijie2",
		"west" : __DIR__"mihang",
                "east" : __DIR__"bank",
	]));
	set("outdoors", "����");
	setup();
}
