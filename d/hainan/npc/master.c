#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int HAVE_WEAPON=1;

int give_weapon();


void create()
{
        set_name(HIY"梵音神尼"NOR,({"fan yin", "shenni", "nigu","master"}));
       set("long",
"神尼名动武林,是当世两大神尼之一,据说她的武功已经到了神而名之的地步.\n");
       set("title", YEL"白云庵主持"NOR);
       set("gender", "女性");
       set("age", 76);
       set("attitude", "friendly");
       set("class","nigu");
       set("rank_info/respect", "神尼");
       set("per", 30);
        set("int", 30);
        set("inquiry", ([
                        "兵器" : (: give_weapon :),
                    "宝刃":(:give_weapon:),
                                    "宝刀":(:give_weapon:),

                ]) );   

       set("max_kee", 3000);
       set("max_gin", 3000);
       set("max_sen", 3000);
       set("force", 3000);
       set("max_force", 3000);
       set("force_factor", 60);
       set("combat_exp", 8800000);

       set_skill("literate", 380);
       set_skill("unarmed", 380);
       set_skill("dodge", 380);
       set_skill("force", 380);
       set_skill("parry", 380);
       set_skill("persuading", 380);
       set_skill("mahayana", 380);       
       set_skill("buddhism", 380);       
       
       set_skill("sword", 380);
	set_skill("qingyun-shou", 280);
	set_skill("panyang-zhang", 280);
	set_skill("liuyue-jian", 280);

	set_skill("wuzhan-mei",300);
	set_skill("zhemei-shou",300);
	set_skill("liuyang-zhang",300);
        set_skill("tianyu-qijian",300);
	set_skill("yueying-wubu",300);
	set_skill("bahuang-gong", 300);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
        map_skill("strike","liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
        map_skill("sword","tianyu-qijian");

        prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: perform_action, "sword.kuangwu" :),
                (: perform_action, "sword.san" :),
                (: perform_action, "strike.zhong" :),
                (: perform_action, "strike.lianzhong" :),
                (: perform_action, "hand.tanmei" :),
                (: perform_action, "hand.zhemei" :),
                (: perform_action, "sword.san" :),
                (: perform_action, "sword.yushijufen" :),
                (: perform_action, "dodge.yueguangruying" :),                
        }));       
	set_temp("apply/attack",220);
	set_temp("apply/defense",220);
	set_temp("apply/armor",220);
	set("max_neili",3500+random(5550));
	set("max_jing",3500+random(5550));
		set("max_qi",3500+random(5550));	


create_family("白云庵", 3, "传人");
setup();

        carry_object("/d/hainan/obj/bai_cloth")->wear();
        carry_object("/d/hainan/obj/yuruyi")->wield();
        add_money("gold.c",10);
}



int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "nigu");
}
int give_weapon()
{  
  object me,ob;

  me=this_player();
if ((me->query("family/master_id")=="zhongling")&&(me->query("family/family_name")=="白云庵"))
 {
  if( me->over_encumbranced() ) return notify_fail("你已经负荷过重了！\n");

  if(HAVE_WEAPON==0)
    command("say 你来晚了，这东西已经给人取走了。");  
  else  
  {
  clone_object("/d/hainan/obj/hanyue.c")->move(me);

    command("say 钟灵这小丫头真是胡闹,这件东西你就拿去吧。");  
    message_vision("梵音神尼给$n一把寒月斩。\n",this_object(),me);   
    
    HAVE_WEAPON=0;   
  }

  return 1;
 }
else
 command("say 老尼哪来的什么神兵利刃呀,你别听那些小丫头乱说!\n");
return 1;
}

