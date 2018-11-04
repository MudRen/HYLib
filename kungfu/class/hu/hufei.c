// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// hufei.c ���

#include <ansi.h> 

inherit NPC; 
inherit F_MASTER; 
string ask_me();
string ask_book();
void do_kill(object ob);
// inherit F_NOCLONE;




    
void create() 
{ 
        object ob; 
        set_name("���", ({"hu fei", "hu", "fei"})); 
        set("gender", "����"); 
        set("nickname", HIW "ѩɽ�ɺ�" NOR); 
        set("age", 25); 
        set("long", @LONG 
�����Ǻ�һ��֮�Ӻ�쳣������书��ǿ����� 
û���ڽ�����������š�ѩɽ�ɺ��������� 
һ����ɫ�������������һ�ѿ������ܾɵĵ��� 
������ף�����������һͷŨ����ȴ����衣 
LONG 
        ); 
        set("attitude", "peaceful"); 
        set("shen_type", 1); 
        set("str", 45); 
        set("int", 30); 
        set("con", 30); 
        set("dex", 30); 
        
        set("qi", 25200); 
        set("max_qi", 25200); 
        set("jing", 23500); 
        set("max_jing", 23500); 
        set("neili", 26500); 
        set("max_neili", 26500); 
        set("jiali", 180); 
        set("combat_exp", 7000000); 
        set("level", 50);
        set("score", 20000); 
        
        set_skill("force", 440); 
        set_skill("lengyue-shengong", 440); 
        set_skill("blade", 460); 
        set_skill("baisheng-daofa", 460); 
        set_skill("hujia-daofa", 460); 
        set_skill("dodge", 460); 
        set_skill("sixiang-bufa", 460); 
        set_skill("taxue-wuhen", 460);
        set_skill("parry", 440); 
        set_skill("throwing", 460); 

        set_skill("strike", 440); 
        set_skill("tianchang-strike", 440); 
        set_skill("cuff", 440); 
        set_skill("hujia-quan", 440); 
        set_skill("literate", 480); 
        set_skill("martial-cognize", 340); 

        map_skill("force", "lengyue-shengong"); 
        map_skill("blade", "hujia-daofa"); 
        map_skill("dodge", "sixiang-bufa"); 
        map_skill("parry", "hujia-daofa"); 
        map_skill("strike", "tianchang-strike"); 
        map_skill("cuff", "hujia-quan"); 
           
        prepare_skill("strike", "tianchang-strike"); 
        prepare_skill("cuff",   "hujia-quan"); 
        
        
        create_family("�������", 7, "����"); 
        
        set_temp("apply/attack", 120);
        set_temp("apply/defense", 120);
        set_temp("apply/armor", 120);
        set_temp("apply/damage", 520);
	set("inquiry",([
		"����":     (: ask_me :),
		"����":     (: ask_book :),
		"���ҵ���": (: ask_book :),
		"�ֻ�":     "�ֻ���������ҷ�ɱ�������ɡ�\n",
		"��һ��":   "�ɶ�������һ�����ҵ��������Ҵ�û��������\n",
		"���˷�":   "���˷���ͼҸ��������Ҹ�ȴ�������Ľ��¡�\n",
		"������":   "��֪ʲôʱ�����ټ����������\n",
		"����":   "��֪ʲôʱ�����ټ����������\n",
		"��������":   "��֪ʲôʱ�����ټ����������\n",
		"������":   "������Ϊ�Ҷ����ġ�\n",
		"�԰�ɽ":   "�������������? \n",
		"Ԭ����":   "���ˣ��������������ˡ�\n"
	]));
        
        set("chat_chance_combat", 120); 
        set("chat_msg_combat", ({ 
                (: perform_action, "blade.huanying" :),
               	(: perform_action, "blade.lian" :),
                (: perform_action, "blade.xian" :), 
                (: perform_action, "blade.zhui" :), 
                (: perform_action, "blade.cang" :), 
                (: perform_action, "cuff.kuai" :), 
                (: perform_action, "strike.jian" :), 
                (: perform_action, "dodge.fei" :), 
                (: exert_function, "recover" :), 
                (: exert_function, "powerup" :), 
        })); 
        
        set_temp("apply/damage", 100); 
        set_temp("apply/unarmed_damage", 100); 
        set_temp("apply/armor", 200); 
 	set_temp("apply/attack",190);
	set_temp("apply/defense",190);
	set_temp("apply/armor",1800);
	set_temp("apply/damage",800);        
            
        set("master_ob",5);
	setup(); 
        
  
          
        carry_object("/clone/cloth/cloth")->wear(); 
        carry_object("/d/guanwai/npc/obj/cwbdao");
        carry_object("/d/zhongzhou/npc/obj/lengyuedao")->wield();       
        set("startroom", "/d/guanwai/xiaowu");  
        // check_clone(); 
} 

void attempt_apprentice(object ob) 
{ 
        
        if (ob->name(1) == "��һ��") 
        { 
                command("say �Ҳ٣��������ҵ����Ӱ���"); 
                return; 
        } 
        
        if (ob->name(1) == "���") 
        { 
                command("say �����̵ģ���զҲ��������֣�"); 
                return; 
        } 
        
        if (ob->name(1) == "����" || ob->name(1) == "����") 
        { 
                command("say �����������֣������������Ҳ̫�����ˡ�"); 
                return; 
        } 
 
        command("recruit " + ob->query("id")); 
        command("say �����ұ������㣬���Ǻ��һ�Ҫ��������������"); 
        return; 
} 

string ask_me()
{
	object ob, me;
	
	me = this_player();
	if((int)me->query("shen") < 0)
	{
		me->set_leader(ob);
		call_out("do_kill",1,this_player());
	}
	else if((int)(me->query("shen")<100000))
		return "����Ŀǰ����Ϊ�ǲ�������ѵ��ġ�\n";

   	else if((int)(me->query("shen") > 100000))
	{
		if(query("baodao_count") > 0)
		{		
	    		call_out("waiting",0,me,ob);
			add("baodao_count", -1);
    			ob = new (__DIR__"obj/cwbdao");
    			ob->move(me);
			command("rumor "+me->query("name")+"�õ�������������\n");
			return " �ðɣ���Ѵ��������������㣬ϣ����ú���������\n";
		}
		else return "�������ˣ�������ѵ��Ѳ��ڴ˴���\n";
	}

}

void do_kill(object ob)
{
	object me, room1;       
	me = this_object();
//	room1 = environment(me);
 
//	if (room1->query("no_fight"))
//	    room1->set("no_fight", 0);
 
	if (interactive(ob))
	{
		command("say ����������Ҵ��ұ��������⣬������������\n");
		me->set_leader(ob);
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
 
}	

int accept_object(object me, object ob)
{
	int i;
	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, me) ) return notify_fail("��û�����������");
	if ( (string)ob->query("id") == "yan ji") 
	{
		write(HIC "\n���˵������λ" + RANK_D->query_respect(me)+"����˴����£�����ʵ��֪����Ϊ����\n");
		write(HIC "\n��쳴�ϲ�����������벻����Ҳ�н��죡�������䣬���ֻ���Ϊ���Ρ�\n"NOR);
                call_out("destroying", 1, this_object(), ob);
//		ob->die();
		me->set_temp("marks/hujiadaopu",1);
        }
	return 1;
}

string ask_book()
{
	object ob, me;
	
	me = this_player();
	if (!me->query_temp("marks/hujiadaopu",1)) return "��˵ʲô? \n";
	if((int)(me->query("shen")<100000))
		return "����������С֮�֣��������ֻ��ڶ���\n";

   	else 
	{
		if(query("book_count") > 0)
		{		
		write(HIC "���˵��ת����ֻ�ʬ�����ѳ�һ���ƾ��鱾�����˸��㡣\n");
	    		call_out("waiting",0,me,ob);
			add("book_count", -1);
    			ob = new ("/clone/book/blade_book");
    			ob->move(this_player());
			command("rumor "+me->query("name")+"�õ����ҵ�������\n");
			return "�Ȿ���ױ��⹷����ռ��ʱ�ˣ����ھ�������ɡ�\n";
		}
		else return "�������ˣ����ڵ����Ѳ��ڴ˴���\n";
	}

}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}
