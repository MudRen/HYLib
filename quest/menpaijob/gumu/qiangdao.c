//snowman 28/02/98
#include <ansi.h>
inherit ITEM;
int j=3;
void create()
{
        set_name("�ɹž���", ({ "mengurenma"}));
        set("unit", "ֻ");
        set_weight(90000000);
        set("long", "
һֻԶ���������ɹž��ӣ������в��ٸ��֡��м��
��һ����죬�ƺ�д�š��ɹŻ��̷������������֡�����\n");
        set("no_get", 1);
        set("no_drop", 1);
	 set("no_put",1);
}

void init()
{ remove_call_out("aaa");
  call_out("aaa", 120, this_object());  
  add_action("do_rob", "qianru");
}

int do_rob()
{
   object me, ob;   
   string arg;
   int stage, i;
   me = this_player();
   ob = this_object();
   stage = 0;
   arg = query("arg");

   if(!living(me)) return 0;
   if(!me->query("kill_gumu")) 
       return notify_fail("�㵨�Ӳ�С���������ɹŴ�����ԣ�\n");

   message_vision(HIY"$Nһ����,Ǳ����$n !!"+me->name()+"��ʼǱ���ɹŴ���ڣ�\n"NOR, me, ob);
   me->set_temp("xx_rob", 1);
   remove_call_out("make_bs");
   call_out("make_bs", 6, me, ob); 
   return 1;     
}
void make_bs(object me, object ob)
{
    object *obn,room,obt;
    int i;
    me = this_player () ;
    ob = this_object() ;

    if(!( room = find_object("/quest/menpaijob/gumu/mengu")) )
          room = load_object("/quest/menpaijob/gumu/mengu");

if (!present("yuanshuai", room))
{
	obt = new("/quest/menpaijob/gumu/guan");
	obt->move(room);
	obt->set("startroom", base_name(room));
}

       me ->move(room) ;
        obn = all_inventory(environment(me));
      for(i=0; i<sizeof(obn); i++)
      if( obn[i]->is_character() && obn[i]!=me
      && obn[i]->query("id")=="yuanshuai" )
{
    message_vision(HIW"�����ڷ���������ɾ�����ͼ�ˡ�\n"NOR, me);
    destruct(ob);
}

message_vision(HIG"�����˰��죬����û�ҵ�ʲô!ֻ�����˳���!!\n"NOR, me);
me->delete("kill_gumu");
me->delete("kill_gumu");
me->apply_condition("gumu_busy",0);
me->move("/d/xiangyang/southgate2");

    destruct(ob);
}

void aaa(object me)
{
       message_vision("$Nת������Сɽ��Ͳ����ˡ�\n",me);       
       destruct(me);
       return;
}

