// /u/beyond/ningbo/kedian.c �͵�
inherit ROOM;

void create()
{
	set("short", "�͵�");
	set("long", @LONG
�������������һ��С�͵꣬�͵���ſ�վ��һλ��С�����������߹�
����Ц�Ǻǵ�������к����͵��������һ����ǣ�ר��Ϊ��������Ĺ���
�ÿ��ǻ���ι�����ġ�ǽ�Ϲ���һ������(paizi)��
LONG
	);

	set("valid_startroom", 1);
        set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "¥���ŷ���ÿҹ����������\n",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));

	set("exits", ([
	"north" : __DIR__"ningbocheng",
        "up" : __DIR__"kedian2",
        "west" : __DIR__"majiu",
        "northeast" : __DIR__"dongqianhu",
        
	]));

	setup();
	
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
	return notify_fail("��ô�ţ����ס����\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
	return notify_fail("�͹��Ѿ��������ӣ���ô��ס��������أ�
���˻���ΪС���ź����أ�\n");

	return ::valid_leave(me, dir);
}
