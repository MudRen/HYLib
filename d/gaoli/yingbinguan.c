// /d/gaoli/yingbinguan.c
// Room in ����
inherit ROOM;

string look_sign(object me);

void create()	
{
	set("short", "ӭ����");
	set("long", @LONG
��������վ�ڸ�����ӭ�����ӭ���ݲ����д�ʹ�ڣ����д���·
���̣�������ԭ�����˶�ϲ���ۼ������ｻ����;�ϵļ��ţ���Ҳ����
����������������Ȥ����Ϣ�������ſڵĵط���һ����ľ��ɵ�����
(sign)��
LONG
	);
set("valid_startroom", 1);
set("item_desc", ([
		"sign": (: look_sign :),
		]));
set("exits", ([
                "north":__DIR__"yudao8",
                "up":__DIR__"kefang",
	]));
       setup();
	
	
set("objects", ([
	__DIR__"npc/xiaoer" : 1, 
]));

	setup();
	}


string look_sign(object me)
{
	if( wizardp(me) )
    return "����д�����͹��ջ��\n";
	else
	return "����д���������ŷ���ÿҹ����������\n";
}
int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up"&&me->query("family/family_name")!="�Ľ���" )
		return notify_fail("��ô�ţ����ס����\n");

	if ( me->query_temp("rent_paid") && dir == "north" )
		return notify_fail("�͹��Ѿ��������ӣ���ô��ס��������أ����˻���ΪС���ź����أ�\n");

	return ::valid_leave(me, dir);
}
