//ouyangfeng.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("ŷ����", ({ "ouyang feng", "ouyang", "feng" }));
	set("long", "���ǰ���ɽׯ�����ųơ���������ŷ���档\n"
		   +"����ϰ���������澭���߻���ħ���ѱ�þ�\n"
		   +"����ң�������ͷɢ����\n");
	set("title", "����ɽׯ��");
	set("gender", "����");
	set("age", 53);
	set("nickname", HIR "����" NOR);
	set("shen_type",-1);
	set("shen", -150000);
	set("attitude", "peaceful");

	set("str", 60);
	set("int", 69);
	set("con", 60);
	set("dex", 68);

	set("qi", 29500);
	set("max_qi", 29500);
	set("jing", 26900);
	set("max_jing", 26900);
	set("neili", 38000);
	set("max_neili", 38000);
	set("jiali", 150);
        set("apply/attack",  230);
        set("apply/defense", 230);
	set("combat_exp", 16500000);
	set("score", 200000);
set_skill("qixian-wuxingjian", 300);
set_skill("cuff", 300);
set_skill("cuff", 300);
set_skill("lingshe-quan", 300);
set_skill("zhaosheshu", 300);
set_skill("yangsheshu", 300);
	set_skill("sword", 280);
	set_skill("force", 250);
	set_skill("unarmed", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("strike",170);
	set_skill("hand",170);
	set_skill("training",300);
	set_skill("staff", 250);
	set_skill("hamagong", 300);
	set_skill("chanchu-bufa", 300);
	set_skill("shexing-diaoshou", 300);
	set_skill("lingshe-zhangfa", 300);
	set_skill("hamashengong", 300);
	
	map_skill("strike", "hamashengong");
	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("unarmed", "shexing-diaoshou");
	map_skill("hand", "shexing-diaoshou");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "reserve" :),
                (: perform_action, "staff.saoluoye" :),
                (: perform_action, "staff.shoot" :),
                (: perform_action, "staff.saoluoye" :),
                (: command("unwield shengzhang") :),
                (: command("unwield shengzhang") :),
                (: command("wield shengzhang") :),
                (: command("wield shengzhang") :),
                (: perform_action, "strike.hama" :),                
                (: perform_action, "strike.hama" :),                
                (: perform_action, "hand.diaoshou" :),                
                (: perform_action, "hand.diaoshou" :),                
        }) );
	create_family("����ɽ��",1, "��ɽ��ʦ");
        set("chat_chance",2);
        set("chat_msg",({
         "ŷ������������������հ���ɽ�ɲ����ذԽ����ء�\n",
         "ŷ��������Ҷ�ŷ���˱��ܹ��������ɽ���۷磡\n",
         "ŷ������������ն����������ģ�\n",
        }));
	setup();
	carry_object("/d/baituo/obj/shenshezhang")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",20);
}

void attempt_apprentice(object ob)
{
  if((int)ob->query("combat_exp")<100000)
        {
          message_vision("ŷ�����$NЦ������ľ���̫����,�һ��������㣡\n",ob);
	return ;
         }
   message_vision("ŷ��������$N��ͷ��΢΢���˵�ͷ��\n",ob);
   command("recruit " + ob->query("id"));
   return;
}

