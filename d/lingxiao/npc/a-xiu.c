//LUCAS 2000-6-18
#include <ansi.h>

inherit NPC;

string ask_staff();
void create()
{
        set_name("����",({"a xiu","xiu"}));
        set("gender", "Ů��");
        set("nickname", HIW"������С����"NOR);
	set("age", 16);
	set("long", 
               "����������������Ů,�귽ʮ���꣬��������\n"
               "����ɰ�,��ֱ���Ǵ�ѩɽ�����ǵ�С����.\n");

        set("attitude", "peaceful");

        set("str", 25);
        set("count",1);
        set("con", 30);
        set("per", 30);
        set("int", 24);
        set("dex", 30);
        set("neili", 1000);
        set("max_neili", 1000);
        set("qi", 1800);
        set("max_qi", 1800);
        set("jing", 1500);
        set("max_jing", 1500);
        set("inquiry", ([
            "ʯ����"   : "���ȥ�����͵�,��֪����������ô����?",
            "������"   : "ֻ���Ҳ�����ô����,����ô����ô����?",
            "ʯ����"   : "�Һ�������---��ȥ��������ɱ�˰ɡ�",
            "����"   : "�����ҵ�ѽ��",
            "������"   : "������үүѽ��",
            "������" : (: ask_staff :),
        ]) );

        set("combat_exp", 50000);
        set("shen_type", 0);
        set("chat_chance", 5);
        set("chat_msg", ({
       "����������ƽ����̶ˮ,˵:��̶�����,���������ʲô������\n", 
       "���忴��Զɽ�����ư��ƣ�̾������磬��Ҫʲôʱ��Ŵ����͵�������\n", 
       "�����Ȼ��򭲻�죬����������ʲô����֮�¡�\n",
        }) );
        set("score", 2000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :)
        }) );

        set_skill("unarmed", 40);
        set_skill("sword", 60);
        set_skill("force", 60);
        set_skill("parry", 60);
        set_skill("dodge", 60);
        set_skill("literate", 40);

        set_skill("xueshan-sword", 160);
        set_skill("bingxue-xinfa", 160);
        set_skill("snow-zhang", 160);
        set_skill("snowstep", 160);

        map_skill("sword", "xueshan-sword");
        map_skill("parry", "xueshan-sword");
        map_skill("force", "bingxue-xinfa");
        map_skill("unarmed", "snow-zhang");
        map_skill("dodge", "snowstep");
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        create_family("������", 7, "����");
        setup();

	
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/money/gold.c");
}
string ask_staff()
{
        object ob;
        object me;
        me = this_player();

        if(query("count") < 1)
                return "��λ"+RANK_D->query_respect(me)+"�����Ǳ�Ǹ���������Ѿ����˰��Ҹ����̴�ȥ�ˡ�";
        if(me->query("combat_exp")<200000)
        return "���书��δ���ң������Ұѽ����Ƚ����㣿";
        add("count", -1);
        ob=new("/d/lingxiao/obj/jinwu-staff");
        ob->move(this_player());
        return "��λ"+RANK_D->query_respect(me)+"������Ұ���ѽ����ȴ��������̣����Ƕ�л�ˡ�";
}

void attempt_apprentice(object ob)
{
        command("say ���ǲ���ͽ�ģ����������ʦ���Ǻ��ˡ�");
}

