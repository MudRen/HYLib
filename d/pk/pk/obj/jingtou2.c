#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��ͷ", ({ "jingtou" }) );
        set("gender", "����");
        set("env/invisibility", 3);    
        set_skill("dodge", 500);
//        set_skill("longfeng-xiang", 500);
//        map_skill("dodge", "longfeng-xiang");       
set_temp("no_kill",1);
        set("attitude", "friendly");
        set("location", 1);
        set_temp("apply/id", ({ "" }));
        set_temp("apply/short", ({""}));
        set_temp("leitai", 1);
        setup();
}

void do_setup(object me, object target)
{
        set("master", me);
        set("target", target);
        this_object()->set_leader(target);  
        this_object()->move(environment(target));  
        "/cmds/std/look"->look_room(this_object(), environment(target));  
        call_out("checking", 1, target);          
}

void do_remove()
{ 
   destruct(this_object());  
}

int checking(object target)
{
       object where, me;
       
       if(!objectp(me = query("master"))){
           destruct(this_object());  
           return 0;
        }
        
       if(!objectp(target) || !objectp(where = environment(target))){
message("vision", HIW"\n���Խ�ɽׯ����Ȼ�䣬�����������һ���쳣�����������˻������ϡ�\n"NOR, environment(me));
           me->delete_temp("jingtou");
           destruct(this_object());  
           return 0;
        }

       if(where != environment())
              this_object()->move(where);
       call_out("checking", 1, target);
       return 1;
}


void relay_message(string msgclass, string msg)
{
        object player, room;
        string *ary;
        int i;

if (!environment(this_object())) return;
        msg = "1\n" +environment(this_object())->query("short")+" - " + msg;
        ary = explode(msg, "\n");
if (sizeof(ary) >30) return;

        if(objectp(player = query("master")))
           room = environment(player);
        for (i=1;i<sizeof(ary);i++)
          if (room) message("vision", HIW"���Խ�ɽׯ��"NOR+ary[i]+NOR+"\n", room);
}

