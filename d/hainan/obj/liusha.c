#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
        object san, sna;
        set("short", "��Į��ɳ");
        set("long", @LONG
�����ڴ��ڿ������¯��ɳĮ�У��ȵ�����������͸������������������
�ķ�������ʲôҲ���������������۹����ķ�ɳ����ʲôҲ����������ؼ�
�·�ֻʣ����һ���ˡ�����»�����������ɳ�������ñ����ĸо���
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"desert1",
  "north" : __DIR__"desert7",
  "south" : __DIR__"desert8",
  "east"  : __DIR__"desert3",
  "down"  : __DIR__"quicksand4",
]));
        set("outdoors", "quicksand");

        setup();
}

void init()
{       object ob;
        object jade;
        int water, food, bellicosity,level,high;
        string outexit;
        mapping rided;
        if( rided = this_player()->query_temp("rided"))
           if( rided["id"] == "luotuo")
               return;
        if( interactive( ob = this_player()))
        {
        water = ob->query("water");
        food = ob->query("food");
        bellicosity = ob->query("bellicosity");
        water -= (random(4)+ 1) * water / 10;
        food -= (random(2)+ 1) * water / 10;
        bellicosity += random(10);
        ob->set("water", water);
        ob->set("food", food);
        ob->set("bellicosity", bellicosity);    
        if( !objectp(jade = present("jade", ob)))
        {
        high=10;
        }
        else
        {
        high=15;
        }
        level=this_player()->query_skill("dodge");
        if (level <10)
        {
                level =10;
        }
        high=high*level/10;
        if (random(high)<1)
        {
                drop_him(ob);
        }
        }
        add_action("do_pull", "pull");
        add_action("do_push","push");
}
int drop_him(object me)
{
        me->start_busy(1);
        call_out("dropnow", 1, me);
        return 1;

}
int dropnow(object me)
{
        message_vision(HIW"$NͻȻ�е��ŵ�������ģ��޴�������", me);
        message_vision("$N���һ�������ã����������������ˡ�\n", me);
        message_vision("$N��������ɳ֮�У���\n"NOR, me);
        me->move(__DIR__"quicksand4");
        return 1;
}
 
int do_pull ( string arg)
{
        object me, who;
        object room;
        me = this_player();
        if ( !arg  ) return notify_fail("��Ҫ��˭������\n");
        room = load_object(__DIR__"quicksand4");
        if(!objectp(who = present(arg, room)) ||  !living(who))
        return notify_fail("��ɳ��û������ˡ�\n");
         message_vision(HIW"$N�þ�ȫ����������$n����ɳ�о��˳�����\n"NOR, me,who);
        who->move(__FILE__);
        return 1;

}

int do_push(string arg)
{
        object room;
        object who;

        room=this_object();
        if (!stringp(arg))
        {
                return 1;
        }
        who=present(arg,room);
        if (objectp(who))
        {
                tell_object(who,this_player()->name(1)+"������һ��\n");
                if (random(who->query_skill("dodge"))<40)
                {
                        message_vision("$N���һ�������ã����������������ˡ�\n", who);
                        message_vision("$N��������ɳ֮�У���\n"NOR, who); 
                        who->move(__DIR__"quicksand4");
                } else {
                        this_player()->start_busy(5);
                        who->kill_ob(this_player());
                }
        }
        return 1;
}
