//ɽ��
// by steel 
#include "ansi.h"
inherit ROOM;

void create()
{
	set("short", "ѩ��");
	set("long", @LONG
	����ѩɽ�е�һ����,���ڷ�ѩ��ȻС�˵�,�����溮�ޱ�,����û
��ʲô�����������������档����������һ��޴�ı��ڡ�  
LONG
	);
	
	set("exits", ([
                "south" : __DIR__"hole9",
                "north":__DIR__"hole"+(random(10)+1),
                "west":__DIR__"hole"+(random(10)+1),
                "northeast":__DIR__"hole"+(random(10)+1),
                  ]));
        set("item_desc",([
             "wall":"�ӱں�����������Щ͸��������ĵط���һ����\n"
             ]) );
	setup();
}
void init()
{
       add_action("do_break","break");
}
int do_break(string arg)
{
      int n;
      object ob,axe;
      ob=this_player();
     if(arg!="bingbi")
      {
       write("��Ҫ����Ҷ�������һ�ҵ�����ô�죬�����Ҳ�����\n"+
"�ҵ������ݲݵ�Ҳ�����\n");
       return 1;        
      }
      
      if( !ob->query_temp("weapon")) 
     {
      write("û�й�����ô�ĸɻ\n");
      return 1;
     }
     axe=ob->query_temp("weapon");
     if(axe->query("id")!="snow axe")
     {
     write("û�к��ʵĹ�����ô�ĸɻ\n");
     return 1;
      }
    message_vision(YEL"$N�ߵ�����ǰ�������Ʊ����������������˹�ȥ��\n"NOR,ob);
    n=(int)ob->query("neili");
    if (n >= 1000)
	{
        message_vision(
        "$Nֻ��һ�����죬���ڱ�����������˸��󶴡���\n", this_player());
        set("exits/southwest", "/d/feihu/bearhole");
        this_player()->set("neili",n-1000);
        remove_call_out("close");
        call_out("close", 5, this_object());
     }
     else
	{
		message_vision(
		RED"���ֻ��һ���ƺߣ�$N�����ڵķ����������ǰһ��....\n"NOR, this_player());
		this_player()->set("neili",0);
		this_player()->unconcious();
    }

    return 1;
}
void close(object room)
{
    message("vision",HIR"������Ȼ������һ�����飬�����ڷ��˸�����ʵʵ��\n"NOR, room);
    room->delete("exits/southwest");
}
