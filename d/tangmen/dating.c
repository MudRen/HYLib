// Room: /d/tangmen/dating.c
//by hem
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "���´���");
	set("long", @LONG
	���������ŵ����´�����ƽʱһ�㲻ʹ�ã�ֻ�������ŷ����ش������ʱ
�����ŵĳ�����������ۼ��������������������ú���֣������а˸�������
������ڷ�����������ƽʱұ��������ʣ����м���Ƴɵ����顣������һ���ܴ��
����ͼ(bagua)��
LONG
	);
	
        set("valid_startroom", 1);

	set("exits", ([
		
		"west" : __DIR__"jingyitang",
		"east" : __DIR__"xingtang",
		"north" : __DIR__"changlang2",
		"south" : __DIR__"changlang8",
	]));
     set("objects", ([
                "quest/menpai/tangmen/shi" : 1,
                "d/biwu/champion_tm" : 1,
 __DIR__"npc/dizi" : 4,
                        ]));

	set("item_desc", ([
		"bagua" : HIY "����ֵİ���ͼ����֪������ΪʲôҪ�������������\n",  
    ]));

	setup();

}
void init()
{
	add_action("do_break", "break");
}
int do_break(string arg)
{
    int n;
	object me = this_player();

    if( !arg || arg!="bagua" )
	{
        write("���ŵĲ���������������ƻ��ģ�\n");
        return 1;
    }
if ((int)this_player()->query_temp("marks/��")){
    message_vision(
    "$N�ߵ�����ǰ�������������ȫ��������˫�����϶������ػ�����ԡ�\n", this_player());


    n = (int)me->query("neili");
    if (n >= 1500)
	{
        message_vision(
        HIR"$Nֻ�����һ�����죡�������Ծ�Ȼ��ת����ǰ����һ������\n"NOR, this_player());
        set("exits/down", "/d/tangmen/qiushi");
        this_player()->set("neili",n-1500);
        remove_call_out("close");
        call_out("close", 10, this_object());
    }
    else
	{
		message_vision(
		HIW"���ֻ��һ���ƺߣ�$N�����Եķ����������ǰһ��....\n"NOR, this_player());
		this_player()->set("neili",0);
		this_player()->unconcious();
    }
me->delete_temp("marks/��");
return 1;    
}
else 
	{write(HIY"�����Կ��а����������������ȶ�Ҫȥ��\n"NOR);
	return 1;}
}

void close(object room)
{
    message("vision","ֻ����һ��¸µ������������ַ���ת�����ָ���ԭ����\n", room);
    room->delete("exits/down");
}
