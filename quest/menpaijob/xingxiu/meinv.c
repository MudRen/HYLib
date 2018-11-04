//snowman 28/02/98
#include <ansi.h>
inherit NPC;
int j=2;
int ask_rob();
void create()
{
        set_name(HIM"����"NOR, ({ "fu shang"}));
       set("long",
                "һ���������̣����ķ�ͷ������������ɵй���\n");
        set("attitude", "friendly");
        set("gender", "����");
        set("age", 58);
        set("per", 24);
        set("str", 30);
        set("int", 37);
        set("con", 36);
        set("dex", 38);
	 set_temp("no_kill",1);
        set("qi", 3500);
        set("max_qi", 3500);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 4000);
        set("max_neili", 4000);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: random_move :),
                (: random_move :),
                (: random_move :),
        }) );
        set("chat_chance", 60);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("env/wimpy", 40);
        setup();
        carry_object("d/gumu/npc/obj/baipao")->wear();
}

void init()
{
  add_action("do_rob", "qiangjie");
  add_action("do_quit","exert");
  add_action("do_guard", "halt");
        remove_call_out("leave");
        call_out("leave",600);
//        call_out("leave",10);
}

int do_rob()
{
   object me, ob;   
   string arg;
   int stage, i;
   me = this_player();
   ob = this_object();
   stage = 0;
if (ob->query_temp("owner/id")!=me->query("id"))
return notify_fail("��������Ҳ���ĳ�����\n");
	if(environment(me)->query("no_fight"))
		return notify_fail("���ﲻ��򶷣�\n");
   if(objectp(present("baobiao", environment(me))))
       return notify_fail("�⼸�����ڿ����书�������㻹���ȴ�����ǰ�����˵�ɣ�\n");  
        ob->start_busy(60);
   message_vision(HIM"$N����$nһ����Ц��"+me->name()+"�ڴˣ���������������??\n"NOR, me, ob);
   me->set_temp("xx_rob", 1);
          me->start_busy(3);
   remove_call_out("make_bs");
   call_out("make_bs", 1, me, ob); 
   return 1;     
}

void make_bs(object me, object ob)
{
   object obj, obj1;
	if (j>0){
	  obj = new(__DIR__"xiake");
         obj->move(environment(me));
	  obj->do_copy(me);
         obj1 = new(__DIR__"xiake");
         obj1->move(environment(me));
 	  obj1->do_copy(me);
          j=j-1;     
        ob->start_busy(60);          
          }
else {
       message_vision(HIW"$N���Ѿ����˱������Ѹ��̴���ˣ�\n"NOR, me);    
       ob->unconcious();
//       me->add("combat_exp",100);
//       me->add("potential",50);
       message_vision(HIR"$N�����ǿ��һЩ��\n"NOR, me);    
       me->delete_temp("rob_start");
       me->delete_temp("xx_rob");
       me->delete_temp("rob_job");
       me->delete_temp("j");       
    }
}

void kill_ob(object ob)
{
        ob->remove_killer(this_object());
        ob->remove_enemy(this_object());
        remove_killer(ob);
        remove_all_killer();
	remove_all_enemy();
        set("qi", 50000);
        set("max_qi", 25000);
        set("jing", 25000);
        set("max_jing", 25000);
        set("neili", 8000);
        set("max_neili", 8000);
        ob->start_busy(6);
        command("peace " + ob->query("id"));
}

void fight_ob(object ob)
{
        ob->remove_killer(this_object());
        ob->remove_enemy(this_object());
        remove_killer(ob);
        remove_all_killer();
	remove_all_enemy();
        set("qi", 50000);
        set("max_qi", 25000);
        set("jing", 25000);
        set("max_jing", 25000);
        set("neili", 8000);
        set("max_neili", 8000);
        ob->start_busy(6);
        command("peace " + ob->query("id"));
}
void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "������һ���˼������ˣ������ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}

int do_quit(string arg)
{
	if(arg=="roar") {
        write(this_player()->query("name")+"�����ﲻ����roar�ɣ�\n");
        return 1;
	}
}

int do_guard(string arg)
{
        write(this_player()->query("name")+"�������ڲ�����halt��\n");
        return 1;
}
