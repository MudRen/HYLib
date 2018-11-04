//snowman 28/02/98
#include <ansi.h>
inherit NPC;
int j=3;
int ask_rob();
void create()
{
        set_name(HIR"̰��"NOR, ({ "guan"}));
       set("long",
                "һ��̰�١�\n");
        set("attitude", "friendly");
        set("gender", "����");
        set("age", 38);
        set("per", 40);
        set("str", 30);
        set("int", 37);
        set("con", 36);
        set("dex", 38);
	 set_temp("no_kill",1);
        set("no_kill", 1);
        set("qi", 3500);
        set("max_qi", 3500);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 4000);
        set("max_neili", 4000);
        set("env/wimpy", 40);
        setup();
        carry_object("d/gumu/npc/obj/baipao")->wear();
}

void init()
{
  add_action("do_rob", "shaguan");
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
	if(environment(me)->query("no_fight"))
		return notify_fail("���ﲻ��򶷣�\n");
   if(!living(ob))
   return notify_fail("û������ɱ˭��!!\n"); 
   if(objectp(present("weishi", environment(me))))
       return notify_fail("�⼸�����ڸ��ֿ����书�������㻹���ȴ�����ǰ�����˵�ɣ�\n");  
        ob->start_busy(60);
   message_vision(HIM"$N����$nһ����У�"+me->name()+"�ڴˣ�����̰��������??\n"NOR, me, ob);
   me->set_temp("xx_rob", 1);
   me->start_busy(3);
   remove_call_out("make_bs");
   call_out("make_bs", 1, me, ob); 
   return 1;     
}

void make_bs(object me, object ob)
{
   object obj, obj1;
int exp,pot;
	if (j>0){
	  obj = new(__DIR__"xiake");
         obj->move(environment(me));
	  obj->do_copy(me);
         obj1 = new(__DIR__"xiake");
         obj1->move(environment(me));
 	  obj1->do_copy(me);
          me->start_busy(2);
          j=j-1;     
          }
else {
        message_vision(HIW"$N���Ѿ����˱�������̰��һ��ɱ�ˣ�\n"NOR, me);    
    if (me->query("taohuajob") == 1) {
       message_vision(HIG"$NΪ������,�书���˽�չ��\n"NOR, me);    
exp=480 + random(700);
pot=350 + random(400);
       me->add("combat_exp",exp);
       me->add("potential",pot);
       me->set("taohuajob",0);
tell_object(me,"�㱻������\n"+chinese_number(exp)+"��ʵս����\n"
		+chinese_number(pot)+"��Ǳ��\n");
       message_vision(HIW"$N���Ѿ����˱�������̰��һ��ɱ�ˣ�\n"NOR, me);    
       message_vision(HIR"$Nһ�����������Լ��Ĵ����ع���ׯ��ϲȥ��!\n"NOR, me);    
       me->move("/d/guiyun/matou");
       }
       ob->die();
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
        command("say ���ٲ���,�书��ʲô��??");
        message_vision(HIC "����shaguan��������\n" NOR,ob);
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
        command("say ���ٲ���,�书��ʲô��??");
        message_vision(HIC "����shaguan��������\n" NOR,ob);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "̰�������˴��������ˡ�\n" NOR,this_object());
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
