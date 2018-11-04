// zhou.c �ܲ�ͨ

#include <ansi.h>

inherit NPC;
//inherit F_SKILL;
int jie_bai();

void create()
{
        set_name("�ܲ�ͨ", ({ "zhou botong", "zhou", "bo tong" }));
        set("gender", "����");
        set("nickname", CYN "����ͯ" NOR ) ;
        set("title", "ȫ��̵�һ������") ;
        set("age", 45);
        set("long",
        "�������˳ơ�����ͯ�����ܲ�ͨ��\n"
        "��������ȫ��������˵�ʦ�ܣ��书��ǿ��������ȴ����������\n"
        "��ССɽ��֮�У�ͷ�����ӳ����ģ�ë���׵���һ��Ұ�ˡ�\n",
        );

        set("combat_exp", 3000000);
        set("shen_type", 1);

        set("max_neili", 35000);
        set("neili", 35000);
        set("jiali", 0);

        set_skill("force", 350);
        set_skill("sword", 300);
        set_skill("unarmed", 300);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("hubo" ,300);
        set_skill("xiantian-qigong",400);
        set_skill("kongming-quan",400);
        map_skill("unarmed","kongming-quan");
        set_temp("apply/attack", 300);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 550);
        set("inquiry", ([
                "�����澭" : "�������澭�������Ҵ��ϣ����б���ɱ���һ���ұƳ�ɽ���Ϳ���ȡ�ߣ�\n",
                "��ҩʦ"   : "��������ʮ���꣬������ұƳ�ɽ����ȡ�������澭����\n����ÿ��������ɨ�˶��飡\n",
                "����"     : "�ҡ��ҡ����Ҳ���ʶ����",
                "��"       : "��Ҫ���ң����������ˣ�\n",
                "���"     :  (: jie_bai :),
                "�ݰ��ֵ�" :  (: jie_bai :),
        ]) );

        create_family("ȫ���", 1, "����");
        set_temp("apply/attack", 550);
        set_temp("apply/defense", 450);
        set_temp("apply/damage", 515);

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

int jie_bai()
{
        object ob ;
        ob = this_player ( ) ;
        if ((string)ob->query("gender") != "����")
        {
                message_vision("\n����ͯ�������´�����$Nһ����˵��������ƽ��ϲͬ������\n"
                "�򽻵���һ��Ů�ˣ�����̫�ࡣ�ҿ��㻹�ǳ�����գ���\n", ob);
                return 1;
        }

        if ((int)ob->query("shen") < -1000)
        {
                say("����ͯ����һ��˵����ƾ�����ֶ���Ҳ�����ҳ��ֵ��ܣ���\n");
                return 1;
        }

        say("����ͯ���˵�˵���ã��Ժ����Ǿ��Ǻ��ֵ��ˣ�\n");
        tell_object(ob,GRN "�ܲ�ͨ���Ķ���˵���ϸ����һ�ס�˫�ֻ���֮������һ·\n"
        "������ȭ�����Դ�������Ϊ������Ӵ��\n" NOR );

        this_player()->set_temp("wantong/�ֵ�", 1);
        return 1;
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("wantong/�ֵ�"))
                return 0;
        return 1;
}

int accept_object(object who, object ob)
{
        if (ob->query("id") == "du she")
        {
                message_vision("$N�ó�һ������������ͯ����ǰ���˻Σ�����������\n"
                "����ͯ�ŵ�����������������⣡���ܱߺ������͸�ˣ�����ͯ�ⷬ�����ˣ�\n\n\n"
                "��������Զȥ�����ڲ������š�\n" ,who);
                destruct(this_object());
                return 0;
        }
        return 0;
}
