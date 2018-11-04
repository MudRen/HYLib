// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h> 


inherit NPC; 
inherit F_MASTER; 




void create() 
{ 
        object ob; 
        set_name("���˷�", ({ "miao renfeng", "miao", "renfeng" })); 
        set("gender", "����"); 
        set("nickname", YEL "�����" NOR); 
        set("title", "��������޵���"); 
        set("age", 48); 
        set("long", @LONG 
�����Ǻųƴ�������޵��ֵġ���������� 
�ֻ������ɫ͸�ƣ��ƺ�������һ�㵭���� 
��ֽ������ĸߴ���࣬��֫�޳���ȴ��ȫȻ 
����ƪ�������˳��档 
LONG ); 
        set("attitude", "friendly"); 
        set("shen_type", 1); 
        set("str", 32); 
        set("int", 31); 
        set("con", 33); 
        set("dex", 31); 
        
        set("qi", 25500); 
        set("max_qi", 25500); 
        set("jing", 24000); 
        set("max_jing", 24000); 
        set("neili", 26800); 
        set("max_neili", 26800); 
        set("jiali", 200); 
        set("level", 50);
        set("combat_exp", 9500000); 
        set("score", 20000); 
        
        set_skill("force", 260); 
        set_skill("lengyue-shengong", 380); 
        set_skill("dodge", 240); 
        set_skill("sixiang-bufa", 380); 
        set_skill("sword", 260); 
        set_skill("miaojia-jian", 380); 
        set_skill("baisheng-daofa", 380);
        set_skill("blade", 240); 
        set_skill("hujia-daofa", 380); 
        set_skill("strike", 260); 
        set_skill("cuff", 260); 
        set_skill("tianchang-strike", 380); 
        set_skill("parry", 360); 
        set_skill("literate", 300); 
        set_skill("martial-cognize", 380); 

        set_skill("daojian-guizhen", 380); 
        set_skill("hujia-quan", 380); 
        

        map_skill("force", "lengyue-shengong"); 
        map_skill("dodge", "sixiang-bufa"); 
        map_skill("sword", "miaojia-jian"); 
        map_skill("blade", "hujia-daofa"); 
        map_skill("parry", "miaojia-jian"); 
        map_skill("strike", "tianchang-strike"); 
        map_skill("cuff", "hujia-quan"); 
        
        prepare_skill("strike", "tianchang-strike"); 
        prepare_skill("cuff", "hujia-quan"); 
           

         
        //create_family("��ԭ���", 6, "����"); 
        create_family("�������", 7, "����"); 
        set("inquiry", ([ 

                "���ҵ���" : "���ҵ��������ҵ���Ӻ����ִ�ϰ�ã����澫���ޱȡ�", 
                "��һ��"   : "���������˼��˶���ɱ�������������ź�������", 
        ])); 
        
        set("chat_chance_combat", 99); 
        set("chat_msg_combat", ({ 
                (: perform_action, "sword.zhai" :), 
                (: perform_action, "sword.zhu" :), 
                (: perform_action, "sword.jian" :), 
                (: perform_action, "sword.gan" :), 
                	(: perform_action, "sword.lian" :), 
                (: perform_action, "strike.dan" :), 
                	(: perform_action, "dodge.fei" :), 
                (: perform_action, "strike.duo" :), 
                	(: perform_action, "strike.huang" :), 
                (: perform_action, "cuff.kuai" :), 		
                (: exert_function, "recover" :), 
                (: exert_function, "powerup" :), 
        })); 
if (random(3)==0)
{
	        set("isok",1);
	        map_skill("sword", "daojian-guizhen"); 
        map_skill("blade", "daojian-guizhen"); 
        map_skill("parry", "daojian-guizhen"); 
        set("chat_chance_combat", 99); 
        set("chat_msg_combat", ({ 
                (: perform_action, "sword.feidao" :), 
                (: perform_action, "sword.feng" :), 
                (: perform_action, "sword.guizhen" :), 
                (: perform_action, "sword.hujia" :), 
                	(: perform_action, "sword.tian" :), 
                	(: perform_action, "sword.wolf" :),                 		
                	(: perform_action, "sword.xue" :),                 		                		
                (: perform_action, "strike.dan" :), 
                	(: perform_action, "dodge.fei" :), 
                (: perform_action, "strike.duo" :), 
                	(: perform_action, "strike.huang" :), 
                (: perform_action, "cuff.kuai" :), 		
                (: exert_function, "recover" :), 
                (: exert_function, "powerup" :), 
        })); 
 }       
        set_temp("apply/damage", 100); 
        set_temp("apply/unarmed_damage", 100); 
        set_temp("apply/armor", 200); 
	set_temp("apply/attack",190);
	set_temp("apply/defense",190);
	set_temp("apply/armor",1800);
	set_temp("apply/damage",800);        
        set("master_ob",5);
	setup(); 
        
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear(); 
if (query("isok")==1)
{
        carry_object("/d/zhongzhou/npc/obj/jundao"); 

}
} 
        
void attempt_apprentice(object ob) 
{


        
        if (ob->name(1) == "���˷�") 
        { 
                command("hmm"); 
                command("say ����ôҲȡ������֣�"); 
                return; 
        } 
        
        if (ob->name(1) == "������") 
        { 
                command("hmm"); 
                command("say ��Ͳ��ܻ���������֣�"); 
                return; 
        } 
        
        if (ob->name(1) == "����" || ob->name(1) == "������") 
        { 
                command("hmm"); 
                command("say �㰲��Ҫ���������ǲ��ǣ�"); 
                return; 
        } 
        
        command("sigh"); 
        command("recruit " + ob->query("id")); 
        command("say �ұ��Ѵ��㲻��ͽ�ܣ��������������硢�����ҵķ�������ƽϢ��"); 
        command("say �������洫��ʮ������ҽ������Ҵ�ʧ����δ��̫����Т��"); 
        return; 
} 
 
int recognize_apprentice(object me, string skill) 
{

        
        if ((int)me->query("shen") < 0) 
        {
                command("sigh"); 
                command("say ����������а·���ҿɲ��ܽ�����ҽ���"); 
                return -1; 
        }
        
        if (me->query("combat_exp",1)<=400000)
        {
                command("say ���ʱ����̫ǳ�������ȴ�û�����˵�ɡ�");
                return -1;
        }

        if (skill != "miaojia-jian" && skill != "sword")
        {
                command("say ��ֻ���������������ҽ�������ľͲ�Ҫ�������ˣ�"); 
                return -1;
        }

        if (me->query_skill(skill, 1) >= 400) 
        {
               command("say ���ˣ��Ҿͽ��㵽����ɣ��书����" 
                       "Ҫ���Լ����о����ǣ�"); 
               return -1; 
        }
        
        command("say ���ڵ��������˼��˶���ɱ���˺�һ���������ź����������ϣ��Ҿʹ�����ҽ�����"); 
        return 1;
}
        
