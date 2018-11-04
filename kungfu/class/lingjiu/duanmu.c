#include <ansi.h>;


inherit NPC;
inherit F_MASTER;


mixed ask_me();

void create()
{
        set_name("��ľԪ", ({ "duanmu yuan", "duanmu", "yuan"}));
        set("gender", "����");
        set("title", "���ϵ����涴����");
        set("nickname", HIR "��ȥ����" NOR);
        set("age", 54);
        set("long", @LONG
���ͷ���߾��Ǻ��ϵ���ָɽ���涴������ľ
Ԫ��ֻ����һ�Ŵ��Դ���ͺͺ�أ����ͷ��Ҳ
�ޣ�������Ѫ��ԶԶ��ȥ�������Ѫ��㡣
LONG );
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
    set("pubmaster",1);
        set("qi", 8000);
        set("max_qi", 8000);
        set("jing", 8800);
        set("max_jing", 8800);
        set("neili", 8200);
        set("max_neili", 8200);
        set("jiali", 120);
        set("combat_exp", 2200000);

        set_skill("force", 200);
        set_skill("wudoumi-shengong", 200);
        set_skill("dodge", 180);
        set_skill("feiyan-zoubi", 180);
        set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("martial-cognize", 180);
        set_skill("literate", 140);

        map_skill("dodge", "feiyan-zoubi");
        map_skill("force", "wudoumi-shengong");
        map_skill("parry", "wudoumi-shengong");
        map_skill("unarmed", "wudoumi-shengong");

        prepare_skill("unarmed", "wudoumi-shengong");

        set("inquiry", ([
                "�嶷����" : "�⡭������������ɵػ��ݻ�������һ�Ź���",
                "�ػ�"     : "�ػ����Һ��ϵ���ָɽ���涴һ�ɵĻ�������",
                "������"     : "�����������չ��µ�����������ȫ���������",
                "����"       : "�����������չ��µ�����������ȫ���������",
        ]));

        create_family("���涴", 14, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.gui" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        set("master_ob",3);
	setup();
        carry_object("/clone/misc/cloth")->wear();
}

int recognize_apprentice(object ob, string skill)
{
if (ob->query("family/family_name") == "���չ�"  && ob->query("family/family_name") != "��ң��")
        {
                command("?");
                command("say �������������Ĺ�����");
                return 0;
        }



/*        if (skill != "wudoumi-shengong" && skill != "unarmed")
        {
                command("say ��ֻ�������嶷���񹦺�һЩȭ��֪ʶ����ѧ�����ˡ�");
                return 0;
        }
*/
        if (skill == "unarmed" && ob->query_skill("unarmed", 1) > 179)
        {
                command("sweat");
                command("say ���ˣ����ˣ��������ˣ�ʣ�µ����Լ�ȥ�о���");
                return 0;
        }

        if (! ob->query_temp("can_learn/duanmuyuan"))
        {
                command("sigh");
                command("say �������Ȼ�������������ģ���Ҳֻ�н�����ˡ�");
                ob->set_temp("can_learn/duanmuyuan", 1);
        }
        return 1;
}



 
void attempt_apprentice(object ob)
{
if (ob->query("family/family_name") != "���չ�")
{
 
        command("@@");
        command("say �㡭��û���ɣ���Ȼ��������������Һ��ˡ�");
        command("recruit " + ob->query("id"));
}
}



