#include <ansi.h>

inherit ROOM;
 
int do_pick(string arg) ;

void create()
{
        set("short", "ɽ��");
        set("long",@LONG
��������һ��Сɽ���С�������ߺܰ���ֻ������ԼԼ����������һ��
�ɲݡ��ɲ��Ϻ������һ��ʯϻ(xia)�� ��ͻȻ�ŵ�һ�����ŵ���ζ����Ȼ
�����˳���ס������ȴ����ɨ��Ե�ʡ�
LONG);   
        set("item_desc", ([
        "xia" : @TEXT
����ϸ����һ��ʯϻ�����������ƺ�����һ���飬�ƺ����������ó���(pick book)��
TEXT ]) );
        set("exits", ([
            "out"  : __DIR__"dongkou",
        ]));
//	set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_pick","pick");
}

int do_pick(string arg)
{
       object me,obj;

       me = this_player();
       if( !arg || arg!="book" )
              return notify_fail("��Ҫ��ʲô?\n");
       if ( !me->query("jiuyin/full") && me->query("jiuyin/shang") && !present("jiuyin shangjuan", me) )  {
              obj = new ("/clone/book/jiuyin-shang");
              obj->move(me);
              message_vision("$N��ʯϻ��ȡ��һ���顣\n",me );
message("channel:rumor", MAG"��ҥ�ԡ�ĳ�ˣ�"+this_player()->query("name")+"�õ������澭�Ͼ�����\n"NOR, users());
       }
       else
              return notify_fail("��Ҫ�����Ǳ��飬ȴ�����㿴�����ۣ���ʵ����ʲô��û�С�\n");
       return 1;
}
