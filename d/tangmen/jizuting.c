// Room: /d/tangmen/jizhuting.c
//by hem
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
	���������Ź������˵Ĵ��������ڹ�����������������Ļ���������һ��
�ܴ�Ĺ�������һЩ��Ʒ�����򡣹���������һ����(bian)��
LONG
	);
	

	set("exits", ([
		
		"west" : __DIR__"huayuan12",
		"north" : __DIR__"changlang9",
		"south" : __DIR__"changlang10",
	]));
	set("item_desc", ([
		"bian" : "�����Ǵ��ļ����֣��������������ϸ�����Һ�¶��һ���ǣ�������ʲô������\n",
	]) );

	setup();
}

void init()
{
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
    int n;
	object me = this_player();

    if( !arg || arg!="bian" )
	{
        write("�����Ǽ����������ұ�������ʲô��\n");
        return 1;
    }
message_vision(
    "$N�����Ṧ�����������ϡ�\n", this_player());

    n = (int)me->query("dex");
    if (n >= 18)
	{
        message_vision(
        "$N����һԾ����ƮƮ�䵽�����ϣ�\n", this_player());
        me->move("/d/tangmen/mubian");
        }
    else
	{
	message_vision(
	"���һ��С�������˹�����ˤ�˸����˲档\n", this_player());
	this_player()->unconcious();
         }

    return 1;
}
