// robber1 for dart
//gemini����2000.4.4 ʹ�ø���ʱ���ο�literate�ȼ�

#include <ansi.h>
inherit NPC;
#include "robber.h"
void create()
{ 
        set_name(HIW"�ٷ�"NOR,({"robber"}));
        set("long","����һλؤ����ͽ��\n");
        set("title","��·����");
        set("gender", "����" );
        set("age", random(30)+14);
        
        set("vendetta/authority", 1);
        set("bellicosity", 100000);
        set("max_qi", 2000);
        set("eff_qi", 2000);
        set("eff_qi", 2500);
        set("qi", 2500);
        set("str",25);
        set("dex",30);
        set("con",30);
        set("max_jing", 1000);
        set("jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 20);
	set("shen",-10000);
        set("shen_type", -10);
        set("combat_exp", 500000);

        set_skill("force", 80); 
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
     
        setup();
        carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

void do_change(object ob)
{
      object me;
      mapping hp_status, skill_status;
      string *sname;
      int i, temp;
      me = this_object();
      ob = this_player();       
/*      if ( mapp(skill_status = me->query_skills()) ) {
                skill_status = me->query_skills();
                sname  = keys(skill_status);
                temp = sizeof(skill_status);
                for(i=0; i<temp; i++) {
                        me->delete_skill(sname[i]);
                }
      }

      if ( mapp(skill_status = ob->query_skills()) ) {
                skill_status = ob->query_skills();
                sname  = keys(skill_status);
                temp = skill_status[0];
                for(i=0; i<sizeof(skill_status); i++) {
		  if(sname[i]=="force")i++;
                  if (skill_status[sname[i]] >= temp)
                  { temp = skill_status[sname[i]];}
              }
        }*/
if (!ob->query_skill("force"))
{
temp=10;
}else
temp=(int)ob->query_skill("force",1);

        me->set_skill("huashan-jianfa", temp);
        me->set_skill("unarmed",temp);
        me->set_skill("xianglong-zhang",temp);
        me->set_skill("dodge", temp);
        me->set_skill("sword", temp);
        me->set_skill("parry", temp);
 me->set_skill("huntian-qigong", temp); 
        me->set_skill("dagou-bang", temp); 
        me->map_skill("sword","huashan-jianfa");
        me->map_skill("dodge","xiaoyaoyou");
        me->map_skill("parry","huashan-jianfa");
        me->map_skill("unarmed","xianglong-zhang");
	 me->map_skill("force", "huntian-qigong");
       	me->map_skill("parry", "dagou-bang");
	me->map_skill("staff", "dagou-bang");

        prepare_skill("unarmed", "xianglong-zhang");
       set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.ban" :),
                (: perform_action, "staff.feng" :),
                (: perform_action, "staff.zhuan" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.wugou" :),                
                (: command("unwield yuzhu zhang") :),
                (: command("wield yuzhu zhang") :),
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.hui" :),                
                (: perform_action, "unarmed.fei" :),                
                (: perform_action, "unarmed.zhen" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );


/* copy hp */

        hp_status = ob->query_entire_dbase();
        me->set("str", hp_status["str"]+random(2));
        me->set("int", hp_status["int"]);
        me->set("con", hp_status["con"]+random(2));
        me->set("dex", hp_status["dex"]+random(10));
        me->set("combat_exp",hp_status["combat_exp"]);
if ((int)ob->query_skill("jiuyin-zhengong",1)>480)
{
me->set("qi",(ob->query("max_qi"))/2);
me->set("eff_qi",(ob->query("max_qi"))/2);
me->set("max_qi",(ob->query("max_qi"))/2);
me->set("max_jing",(ob->query("max_qi"))/2);
me->set("eff_jing",(ob->query("max_qi"))/2);        
me->set("jing",(ob->query("max_qi"))/2);
}
}


