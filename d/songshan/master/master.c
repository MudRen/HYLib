//Cracked by Kafei
// /d/bwdh/sjsz/npc/master.c

#include <ansi.h>


inherit NPC;

int auto_perform();

void create()
{
		  set_name("������������", ({ "master" }));
		  set("long","�������۾����֣��������£�����պյĵ�����������������\n");

        set_temp("no_kill",1);
		  set("gender", "����");
		  set("age", 50);
	set("attitude", "friendly");
		  set("shen_type", 1);
		  set("str", 60);
		  set("int", 60);
		  set("con", 60);
		  set("dex", 60);

		  set("max_qi", 18000);
		  set("max_jing", 18000);
		  set("neili", 34000);
		  set("max_neili", 34000);
		  set("combat_exp", 3000000);
		  set("no_get", 1);
		  set("score", 5000);

		  set_temp("apply/armor", 300);
		  set_temp("apply/damage", 110);
	set_temp("apply/attack",100);
	set_temp("apply/defense",200);

	
		  set_skill("force", 300);
		  set_skill("dodge", 300);
		  set_skill("parry", 300);
		  set_skill("sword", 300);
		  set_skill("strike", 300);
		  set_skill("zixia-shengong", 300);
		  set_skill("huashan-shenfa", 300);
		  set_skill("hunyuan-zhang", 300);

		  set_skill("luoyan-jian", 300);
		  set_skill("hengshan-jian", 300);
		  set_skill("songshan-jian", 300);
		  set_skill("shiba-pan", 300);
		  set_skill("duanjia-sword", 300);

		  set_skill("taiji-jian", 300);
		  set_skill("huashan-sword", 300);
		  set_skill("damo-jian", 300);
		  set_skill("huifeng-jian", 300);
		  set_skill("duanjia-sword", 300);
		  set_skill("pixie-jian", 300);
		  set_skill("liuhe-dao", 300);
		  set_skill("taiji-shengong", 300);
		  set_skill("kuihua-xinfa", 300);
		  set_skill("hunyuan-yiqi", 300);
		  set_skill("linji-zhuang", 300);
		  set_skill("kurong-changong", 300);

		  map_skill("force", "zixia-shengong");
		  map_skill("dodge", "huashan-shenfa");
		  map_skill("parry", "huashan-sword");
		  map_skill("sword", "huashan-sword");
		  map_skill("strike", "hunyuan-zhang");

		  prepare_skill("strike", "hunyuan-zhang");



		  set("chat_chance_combat", 40);
		  set("chat_msg_combat", ({
					 (: auto_perform :),
		  }) );

		  set("inquiry", ([
						"��������" : "����������̩ɽ�ɡ���ɽ�ɡ���ɽ�ɡ���ɽ�ɡ���ɽ�ɺϲ����ɡ�",
                  "��ɽ��" : "�ԴӺϲ��������ɺ󣬾�û����ɽ���ˡ�",
                  "а��" : "����а���������ɣ�����ɽ��ѩɽ�ɺ�Ѫ���š�",
                  "����" : "�������������������ɣ��䵱�ɣ���ɽ�ɣ�����μҺͶ����ɡ�",
                  "��������" : "�������������������ɣ��䵱�ɣ���ɽ�ɣ�����μҺͶ����ɡ�",
        ]));


		  setup();

		  carry_object(__DIR__"renshen-guo");
		  carry_object(__DIR__"renshen-guo");
		  carry_object(__DIR__"renshen-guo");
		  carry_object(__DIR__"qinggang-jian")->wield();
		  carry_object("/clone/misc/cloth")->wear();
}

int auto_perform()
{
		  object me = this_object();
		  object ob = me->select_opponent();
		  object w, w1, w2;
		  string skill, action, spforce;
		  int n;


		  if ( !me->is_fighting() ) {
					 if ( (int)me->query("eff_qi") < (int)me->query("max_qi") )
								exert_function("heal");
					 me->set("jiali", 100);

					 return 1;
		  }


		  if( !objectp(w2 = present("xiuhua zhen", me))
		  && query("amount") ) {
					 add("amount", -1);
					 w2 = new(__DIR__"xiuhua");
					 w2->move(me);
                  command("wield xiuhua zhen");
		  }
		  if( !objectp(w2 = present("qinggang jian", me))
		  ) {

		 w2 = new(__DIR__"xiuhua");
		 w2->move(me);
                  command("wield xiuhua zhen");
		  }

		  if( !objectp(w2 = present("xiuhua zhen", me))
		  ) {

		 w2 = new(__DIR__"xiuhua");
		 w2->move(me);
                  command("wield xiuhua zhen");
		  }

		  w1 = present("qinggang jian", me);
		  if( objectp(w1) && objectp(w2) ) n = random(10);
		  else if( objectp(w1) && !objectp(w2) ) n = random(9);
		  else if( !objectp(w1) && objectp(w2) ) n = 5;
		  else {
					 me->set_skill("zixia-shengong", 340);
                me->map_skill("force", "zixia-shengong");
                me->reset_action();
                return perform_action("strike.wuji");
        }                

		  switch(n) {
		  case 0:
                skill = "taiji-jian";
                action = "sword.lian";
					 spforce = "taiji-shengong";
                break;
        case 1:
                skill = "huashan-sword";
                action = "sword.jianzhang";
                spforce = "zixia-shengong";
					 break;
        case 2:
                skill = "damo-jian";
                action = "sword.sanjue";
                spforce = "hunyuan-yiqi";
                break;
        case 3:
                skill = "huifeng-jian";
                action = "sword.mie";
                spforce = "linji-zhuang";
                break;
        case 4:
                skill = "duanjia-sword";
                action = "sword.fenglei";
                spforce = "kurong-changong";
                break;
        case 5:
					 skill = "pixie-jian";
					 action = "sword.sanlianci";
                spforce = "kuihua-xinfa";
					 break;
        case 6:
                skill = "luoyan-jian";
                action = "sword.yunwu";
                spforce = "kurong-changong";
                break;
        case 7:
                skill = "shiba-pan";
                action = "sword.ruhe";
                spforce = "kurong-changong";
                break;
        case 8:
                skill = "songshan-jian";
                action = "sword.xuli";
                spforce = "kurong-changong";
                break;
        case 9:
                skill = "songshan-jian";
                action = "sword.shenfeng";
                spforce = "kurong-changong";
                break;
        }

		  if( objectp(w = me->query_temp("weapon")) ) {
					 if( w == w1 && n < 5 ) {
                        message_vision(HIR"\nͻȻ��$N�ٺ���Ц������\n�漴����" + w->name() + "������ֱ������һ������һ�㣬��ʱ��ʽ��䣡����\n"NOR, me);
                } else if( w == w1 && n == 5 ) {
                        w->unequip();
                        message_vision(w->query("unwield_msg"), me, w);
								w2->wield();
                        message_vision(w2->query("wield_msg"), me, w2);
								message_vision(HIR"\nͻȻ��$N����һ�䣬����" + w2->name() + "�����������ʽ������ס�\n"NOR, me);
                } else if( w == w2 && n < 5) {
                        w->unequip();
								message_vision(w->query("unwield_msg"), me, w);
								w1->wield();
								message_vision(w1->query("wield_msg"), me, w1);
								message_vision(HIG"\n$N�ƺ���������˽�����Ȼ������\n"NOR, me);
					 }
		  } else {
					 if( n < 5 ) {
								w1->wield();
								message_vision(w1->query("wield_msg"), me, w1);
								message_vision(HIG"\n$N�ƺ���������˽�����Ȼ������\n"NOR, me);
					 } else {
								w2->wield();
								message_vision(w2->query("wield_msg"), me, w2);
								message_vision(HIR"\nͻȻ��$N����һ�䣬����" + w2->name() + "�����������ʽ������ס�\n"NOR, me);
					 }
		  }

		  me->map_skill("sword", skill);
		  me->map_skill("parry", skill);
		  me->map_skill("force", spforce);
		  me->reset_action();
		  return perform_action(action);
}


void lose_enemy(object winner)
{
        if (userp(winner)){
	remove_call_out("changeshape");
	call_out("changeshape",0,winner);
	return;
}
}
void changeshape( object winner)
{
	object zheng;
	string name,id,nick;
        object *ob_list;
        int i;

        if(!winner || environment(winner) != environment())
        return notify_fail("����?\n");
        if (!userp(winner))
        return notify_fail("�㲻����ң��ǻ�����.\n");
        if(winner->is_ghost()) return notify_fail("��겻���ԡ�\n");
  if( (int)winner->query_skill("luoyan-jian", 1) < 200 )
return notify_fail("��Ļط����㽣������죬û���ʸ���Ҵ�!\n");
 if( (int)winner->query_skill("shiba-pan", 1) < 200 )
return notify_fail("���̩ɽʮ���̲�����죬û���ʸ���Ҵ�!\n");
 if( (int)winner->query_skill("songshan-jian", 1) < 200 )
return notify_fail("�����ɽ��彣������죬û���ʸ���Ҵ�!\n");
 if( (int)winner->query_skill("liuhe-dao", 1) < 200 )
return notify_fail("���������ϵ�������죬û���ʸ���Ҵ�!\n");
  if( (int)winner->query_skill("hengshan-jian", 1) < 200 )
return notify_fail("��ĺ�ɽ����������죬û���ʸ���Ҵ�!\n");
if (present("wuyue lingqi", winner))
return notify_fail("���Ѿ���������������!\n");
        CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "%s�����ڿ�ʼ���µ��������������ˣ��� \n",
        winner->name(1)));
	name = winner->query("name");
	id = winner->query("id");
	set_name( name , ({ id }) );
	nick = winner->query("nickname");
	delete("env");
//	set("attitude", "aggressive");
        set("combat_exp",winner->query("combat_exp"));
        set("qi",winner->query("max_qi"));
        set("max_qi",winner->query("max_qi"));
        set("jing",winner->query("max_jing"));
        set("max_jing",winner->query("max_jing"));
        remove_all_killer();
	winner->remove_all_killer();
	reset_action();
	delete_temp("already_loaded");
	set("title", HIR "������������" NOR);	
	set("nickname",nick);
	zheng = new(__DIR__"qi");
         ob_list = children(__DIR__"qi");
             for(i=0; i<sizeof(ob_list); i++) 
             if(environment(ob_list[i]))
             {
                ob_list[i]->move(VOID_OB);
		message_vision("�����������컯��һ����â������Զ����\n",ob_list[i]);
                    destruct(ob_list[i]);
             }
	zheng->move(winner);
	message_vision("����������������$Nһ�������������졣\n",winner);
	set_temp("no_kill",1);

	
	   
return;
}

int accept_fight(object me)
{
object ob;
me=this_player();
ob=this_object();
 if( (int)me->query_skill("luoyan-jian", 1) < 200 )
return notify_fail("��Ļط����㽣������죬û���ʸ���Ҵ�!\n");
 if( (int)me->query_skill("shiba-pan", 1) < 200 )
return notify_fail("���̩ɽʮ���̲�����죬û���ʸ���Ҵ�!\n");
 if( (int)me->query_skill("songshan-jian", 1) < 200 )
return notify_fail("�����ɽ��彣������죬û���ʸ���Ҵ�!\n");
 if( (int)me->query_skill("liuhe-dao", 1) < 200 )
return notify_fail("���������ϵ�������죬û���ʸ���Ҵ�!\n");
  if( (int)me->query_skill("hengshan-jian", 1) < 200 )
return notify_fail("��ĺ�ɽ����������죬û���ʸ���Ҵ�!\n");

 if (this_player()->query("combat_exp") < 500000)
 return notify_fail("��Ҫ��Ѱ��·.\n");
       command("say �ã������ҾͿ��Գ�Ϊ��������������");
set("combat_exp",this_player()->query("combat_exp"));
	return 1;
	  
}
void unconcious()
{
    die();
}

void die()
{
        object ob;
        object me;
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);

        if( !ob ) return;
	me = this_object();
	me->remove_all_killer();
	me->set("eff_qi", me->query("max_qi"));
	me->set("qi",     me->query("max_qi"));
	me->set("eff_jing", me->query("max_jing"));
	me->set("jing",   me->query("max_jing"));
	me->set("neili",  me->query("max_neili"));
	changeshape(ob);
	return;
}
void find(string id)
{
object *ulist,*ilist;
object ob;
int i,j;
ulist  =  users();
	i  =  sizeof(ulist);
while (i--) {
	if  (present  ("wuyue lingqi",ulist[i]))
	{
	ilist  =  all_inventory(ulist[i]);
	j=sizeof(ilist);
	while (j--) {
	ob = ilist[j];
	if(ob->query("id")=="wuyue lingqi")
	{
	destruct(ob);
			}
	}
message_vision(HIY"$N���ϵ������������첻������ˡ�\n"NOR,ulist[i]);
	}
}
}


