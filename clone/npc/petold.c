#include <ansi.h>
#include <combat.h>

inherit NPC;
void create()
{
	set_name("����", ({ "pet" }) );
//	set("race", "Ұ��");
	set("age", 1);
	set("str",35);
	set("int",15);
	set("per",15);
	set("tol",15);
	set("con",15);
	set("dex",15);
	set("long", "һֻСССС���\n");
	set("owner","R");
	set("limbs", ({ "ͷ��", "����", "ǰ��", "�ᱳ", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );
        set("obedience",2);
        set("petdie",1);
	set("combat_exp", 100000);
	set_temp("apply/attack", 50);
	set_temp("apply/damage", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/defence",100);
	set("deathstamp",1);
	set_skill("parry", 50 + random(50));
	set_skill("dodge", 50 + random(50));
	set_skill("unarmed", 50 + random(50));
	set_skill("puyaogedou", 50 + random(50));
//	map_skill("unarmed", "puyaogedou");
//	map_skill("parry", "puyaogedou");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.pfm1" :),                
                (: perform_action, "unarmed.pfm2" :),                
                (: perform_action, "unarmed.pfm3" :),                
                (: perform_action, "unarmed.pfm4" :),                
                (: perform_action, "unarmed.pfm5" :),                
                (: perform_action, "unarmed.pfm6" :),                
        }) );


        setup();
}
string query_save_file()
{
        string id;

        id = query("owner");
        if( !stringp(id) ) return 0;
        return sprintf("/data/user/%c/%s", id[0],id+".pet");
}

int save()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) ) {
                assure_file(file+ __SAVE_EXTENSION__);
                return save_object(file);
        }
        return 0;
}

int restore()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) )
                return restore_object(file);
        return 0;
}

void die()
{	
        int i;
        object owner, *enemy;
	int jing,qi,exp;
	//set("deathstamp",time());
	exp = (int) query("combat_exp");
	jing = (int) query("max_jing");
        qi = (int) query("max_qi");
        if(!environment()->query("no_death_penalty"))
	set("combat_exp",exp/10 * 9);
	set("eff_qi",qi);
	set("eff_jing",jing);
	 set("qi",qi);
        set("jing",jing);
        if(objectp(owner=query("possessed")))
        {
                enemy = query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        owner->kill_ob(enemy[i]);
                        enemy[i]->kill_ob(owner);
                }
        }

        }

	save();	
	::die();
}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        if(!objectp(this_object()->query("possessed")))
	{
	set_heart_beat(1);	
	save();
	command("emote һ���Ͳ����ˡ�");
//	message_vision("$Nһ���Ͳ����ˡ�\n",this_object());
        destruct(this_object());
//	return;
	}
//	set_heart_beat(1);
}
/*int heal_up()
{
        if(!objectp(this_object()->query("possessed")))
	{
	set_heart_beat(1);	
	save();
	command("emote һ���Ͳ����ˡ�");
//	message_vision("$Nһ���Ͳ����ˡ�\n",this_object());
        destruct(this_object());
	return 1;
	}
	set_heart_beat(1);
        return ::heal_up() ;
}*/

void init()
{
	if(this_player() == query("possessed"))
	{
	add_action("do_order","order");
	add_action("do_modify","modify");
	add_action("do_gongji","gongji");
	add_action("do_teach","xunlian");
	add_action("do_shape","shape");
	add_action("do_eat","giveeat");
	add_action("do_move","fastmove");
	add_action("do_pfm","petpfm");
	}

}

int do_order(string arg)
{
	int obedience;
	object me = this_player();
	me->add("jing",-5);
	obedience = query("obedience");
	if(random(50) < obedience )
	command( "emote " + arg);
	else
	command("emote �ܲ���Ը�غ���һ����");
	return 1;
}
int do_modify(string arg)
{
	string item, msg;
        object me = this_player();
	if(!arg || sscanf(arg,"%s %s",item,msg) != 2)
	return notify_fail("SYNTAX: modify ���� ����\n");
	if(item == "flee")
	{
		set("env/wimpy", atoi(msg));
                write("�ϣ�\n");
		save();
		return 1;
	}

		
                if(CHINESE_D->check_control(msg))
                return notify_fail("���������п��Ʒ���\n");
//		if( i%2==0 && !is_chinese(name[i..<0]) ) {
                if(!is_chinese(msg))
                return notify_fail("�������������ģ�\n");
                if(CHINESE_D->check_space(msg))
                return notify_fail("�������費���ո�\n");
                if(CHINESE_D->check_return(msg))
                return notify_fail("�������費���س�����\n");
	me->add("jing",-10);
	switch(item)
	{
	case "desc":
		if(CHINESE_D->check_length(msg) > 100)
		return notify_fail("����̫����\n"); 
		set("long",msg+"\n");
		write("�ϣ�\n");
		save();
		return 1;
	case "nickname" :
		if(CHINESE_D->check_length(msg) > 20)
                return notify_fail("����̫����\n");
		set("nickname",msg);
		write("�ϣ�\n");
		save();
                return 1;
	case "title" :
                if(CHINESE_D->check_length(msg) > 10)
                return notify_fail("����̫����\n");
                set("title",msg);
                write("�ϣ�\n");
		save();
                return 1;
	case "arrive_msg" :
                if(CHINESE_D->check_length(msg) > 30)
                return notify_fail("����̫����\n");
                set("arrive_msg",msg);
                write("�ϣ�\n");
		save();
                return 1;
        case "leave_msg" :
                if(CHINESE_D->check_length(msg) > 30)
                return notify_fail("����̫����\n");
                set("leave_msg",msg);
                write("�ϣ�\n");
		save();
                return 1;

	}
	return notify_fail("��Ҫ�޸�ʲô��\n");

}
int  do_eat()
{
	object me, ob;
	object gold;
	int cost = 5;
	me = this_player();
        ob = this_object();
        gold = present("gold_money", this_player());
        if( !gold) return notify_fail("������û�н��ӡ�\n");

        if(me->is_busy())
        return notify_fail("����һ��������û����ɡ�\n");

        if((int) gold->query_amount() < cost)
        return notify_fail("������û����" + sprintf("%d",cost)+ "�����ӡ�\n");
        gold->add_amount(-cost);
        if( ob->query("food") >= ob->max_food_capacity() )
        return notify_fail("���Ѿ���̫���ˣ���Ҳ�������κζ����ˡ�\n");
  	ob->set("food", ob->max_food_capacity());
	ob->set("water",ob->max_water_capacity());
        me->start_busy(2);
        command("emote ���˵Ľ���һ����");
        command("emote ����һ�ڰѻƽ�����ˡ�");
        	return 1;
}

int do_gongji(string arg)
{
	object me,obj;
	me = this_player();
        if( environment(me)->query("no_fight") )
                return notify_fail("���ﲻ׼ս����\n");

if( query_temp("is_rided_by"))
return notify_fail("��ĺ��ﲻ��������������!\n");

        if( !arg )
                return notify_fail("����ɱ˭��\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("����û������ˡ�\n");

      if( environment(me)->query("no_fight") )
        return notify_fail("���ﲻ׼ս����\n");

        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
  
       if( obj->query_temp("no_kill") )
        return notify_fail("���ܴ򣬴򲻵ð���\n");


        if((int)obj->query("age") <= 17 && userp(obj))
        return notify_fail("Ϊ����������ã��Ź�С���Ӱ�.\n");

        if(userp(obj) && (int)obj->query("combat_exp") < this_object()->query("combat_exp"))
        return notify_fail("���ﲻ������Լ��͵���ҽ���.\n");

	message_vision(
	sprintf("$N��$nһָ����%s����������ϣ���\n",this_object()->name()),me,obj);
        me->add("jing",-5);
	add("jing",-10);
        if(random(50) > query("obedience") )
        command("emote �ܲ���Ը�غ���һ����");
	else
	kill_ob(obj);
	return 1;
	
}

int do_teach(string arg)
{
	object me;
	int gin_cost,amount;
        int myskill, itskill;
	me = this_player();
	if(!myskill = me->query_skill(arg,1))
	return notify_fail("���������󻹲����أ�\n");
	if(arg != "unarmed" && arg != "dodge" && arg != "parry"  && arg != "puyaogedou")
	return notify_fail("��ѧ��������ܵģ�\n");
	itskill = query_skill(arg,1);
	if(myskill <= itskill)
	return notify_fail(name()+"�Գ�Ц��Ŀ�������㡣\n");
	if((int)me->query("potential")-(int)me->query("learned_points") < 2)
	return notify_fail("���Ǳ�ܲ�����\n");
	gin_cost =  (int) query_int();
	if((int)me->query("jing") < gin_cost)
	return notify_fail("����Ȼ̫����û�а취�̣�\n");
	me->receive_damage("jing",gin_cost);
	me->add("potential",-2);
	amount = (int)me->query("int") * (int) query("int");
	message_vision(sprintf("$N�����䷳�ؽ�$n��%s����\n",to_chinese(arg)),me,this_object());
	  if(random(50) > query("obedience") )
        command("emote �ܲ���Ը�غ���һ����");
	else 
	{
       improve_skill(arg,amount);
       improve_skill("puyaogedou", random(me->query_int()/2));
	message_vision(sprintf("$N�ƺ����ѧ����һЩ��%s����\n",to_chinese(arg)),this_object());
	}
	return 1;

}
string status_color(int current, int max)
{
        int percent;

        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}
int do_shape(string arg)
{	mapping my;
	string shape;
	int at_pt,pa_pt,do_pt;
	my = query_entire_dbase();
	 printf(HIC"��"HIY"������������������������������������������������������������"HIC"��\n"NOR);
printf("������%s%3d/ %3d %s(%3d%%)   ��Ѫ��%s%3d/ %3d %s(%3d%%)\n",
                status_color(my["jing"], my["eff_jing"]), my["jing"],my["eff_jing"],
                status_color(my["eff_jing"], my["max_jing"]),     my["eff_jing"] * 100 / my["max_jing"],
                status_color(my["qi"], my["eff_qi"]), my["qi"], my["eff_qi"],
                status_color(my["eff_qi"], my["max_qi"]),     my["eff_qi"] * 100 / my["max_qi"]            
	);		
	printf("���ˣ� "HIW"%s"NOR"\t\t���飺 %d\t\t"HIR"ɱ���� %d\n"NOR,
	my["owner"], my["combat_exp"],my["bellicosity"]
	);
        printf("���ǣ� %d\t\t���ʣ� %d\t\t��̬�� %d\n",
        query_int(), query_con(),query_per()
        );
        printf("�ٶȣ� %d\t\t������ %d\t\t���ԣ� %d\n",
        query_dex(), query_str(),query_kar()
        );
          printf("ѱ���ȣ� "HIM"%d"NOR"\t\t���ԣ� %d\n",
         query_obe(), query_tol()
        );
        at_pt= COMBAT_D->skill_power(this_object(), "unarmed", SKILL_USAGE_ATTACK);
        pa_pt= COMBAT_D->skill_power(this_object(), "parry", SKILL_USAGE_DEFENSE);
        do_pt= COMBAT_D->skill_power(this_object(), "dodge", SKILL_USAGE_DEFENSE);
        printf(HIB"�������� %d\t\t\t\t"NOR+HIY"�������� %d\n\n"NOR,
        at_pt+1, pa_pt/2+do_pt/2+1
        );
	printf("/cmds/skill/skills"->pet_skill(this_object()));
	 printf(HIC"��"HIY"������������������������������������������������������������"HIC"��\n"NOR);return 1;
}
void unconcious()
{
object me;string file;
me=this_player();
add("petdie",1);
if (query("petdie")>10)
{
me->delete("marks/pet");
write(HIR"��ĺ���,�������˹���,��������\n"NOR);
}
die();
}

int do_move(string arg)
{

          string pla;
          object me = this_player();
 if( query("up1") < 2 )
return notify_fail("��ĺ��ﻹû�е��ռ�.\n");
if(!query_temp("is_rided_by"))
return notify_fail("�㻹û��������ĺ�����!\n");
if( !me->query_temp("is_riding") )
return notify_fail("�㻹û��������ĺ�����!\n");

if( me->query("jing") < 50 )
               return notify_fail("�㾫�񲻹���ʢ�������ܵ���ô�죡��Բ�����!\n");
if( me->is_busy())
return notify_fail("����������æ����!\n");

if( !environment(me)->query("no_fight"))
{
  message_vision("ֻ���ڰ�ȫ��������ú������!!!\n"
                 ,me);
      	return 1;
}
          if (!arg)
              return notify_fail("����ȥ�����أ�\n");
          if( !wizardp(me) && me->is_fighting()  ) 
          return notify_fail("��ôΣ�գ�������ô����?\n");

          else {
          message_vision(HIG
"$N�����Լ��ĺ�������һ������,Ȼ�����Ծ�ϣ����ֺ��ǽýݡ���\n"+
"$N�����Լ��ĺ�����һ����ȥ�ɡ���ֻ������������ܶ�ȥ������\n\n"NOR, me);
}
          if(arg=="gc") pla = "/d/city/guangchang";
     else if(arg=="xx") pla = "/d/xingxiu/xxh1";
     else if(arg=="mj") pla = "/d/mingjiao/shanmen";
     else if(arg=="em") pla = "/d/emei/qingyinge";
     else if(arg=="shl") pla = "/d/shaolin/guangchang1";
     else if(arg=="lj") pla = "/d/lingjiu/damen";
     else if(arg=="dl") pla = "/d/dali/center";
     else if(arg=="xs") pla = "/d/xueshan/shanmen";
     else if(arg=="wd") pla = "/d/wudang/guangchang";
     else if(arg=="hs") pla = "/d/huashan/zhenyue";
     else if(arg=="tam") pla = "/d/city2/tian_anm";
     else if(arg=="quz") pla = "/d/quanzhen/damen";
     else if(arg=="bt") pla = "/d/baituo/dating";
     else if(arg=="qz") pla = "/d/quanzhou/zhongxin";
     else if(arg=="gm") pla = "/d/gumu/mumen";
     else if(arg=="sz") pla = "/d/suzhou/canlangting";
     else if(arg=="gyz") pla = "/d/guiyun/taihu";
     else if(arg=="xy") pla = "/d/xiangyang/guangchang";

               else {
               message_vision(HIR
"�������˰���,û�ҵ�Ҫȥ�ĵط���\n"NOR, me);
               message_vision(HIR
"Ŀǰ�����ȥ�ĵط�������:
�찲��(tam) ����(dl) Ȫ��(qz) ����(shl)��ɽ(hs) ����(lj)  
 �䵱(wd)    ����(mj) ����(gc) ����(xx) ѩɽ(xs) ��ü(em)  
ȫ��(quz)  ����ɽ(bt) ��Ĺ(gm) ����(sz)����ׯ(gyz)����(xy)  \n"NOR, me);

}
     if (me->move(pla)) {
       message_vision(HIC"\n���ˣ������һԾ,�����Լ��ĺ��\n"NOR,me);
me->add("jing",-30);
me->start_busy(4);
}
     return 1;
}


int do_pfm(string arg)
{
	int obedience;
	object me = this_player();
if( query("up1") < 1 )
return notify_fail("��ĺ��ﻹû���������.\n");
if( !is_fighting())
return notify_fail("��ĺ�������û��վ����?\n");
if( query_temp("is_rided_by"))
return notify_fail("��ĺ��ﲻ��������������!\n");

if( me->is_busy())
return notify_fail("��������æ����!!\n");
if( me->query("jing") < 50 )
   return notify_fail("�㾫�񲻹���ʢ����Բ�����!\n");


	me->add("jing",-5);
        me->start_busy(random(7));
	obedience = query("obedience");
	if(random(50) < obedience )
{
	command("emote ����Ŭ����һ�¡�");
command("perform pfm1");
command("perform pfm2");
command("perform pfm3");
command("perform pfm4");
command("perform pfm5");
command("perform pfm6");
}
	else
	command("emote �ܲ���Ը�غ���һ����");
	return 1;
}

