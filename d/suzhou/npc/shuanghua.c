inherit NPC;
int ask_me();

void create()
{
        set_name("��˪��", ({ "ling shuanghua", "ling", "shuanghua" }));
        set("long", "�������������ף������˵���ա�\n");
        set("gender", "Ů��");
        set("age", 18);

        set("attitude", "friendly");
        set("inquiry", ([
            "����" : (: ask_me :),
            "�����" : (: ask_me :),
            "����" : "�����ҵ�����Ѿ�ߡ�",
            "����˼" : "�����ҵ��������������",
       ]) );

        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 5);

        set("combat_exp", 2000);
        set("shen_type", 1);
        setup();
           carry_object(__DIR__"obj/necklace")->wear();
          carry_object("/d/city/obj/pink_cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
             command("wanfu " + me->query("id"));
        command("say ��λ"+RANK_D->query_respect(me)+"����"+
                "���ջ��İɣ���֪�������ڻ�԰������ʲô����һ��ȥ�ͻᱻѬ���ģ�"+
                "�㻹����ذɡ�");
}

        
int accept_kill(object me)
{
        command("say ������������" + me->name() + "���" + RANK_D->query_rude(me) + "Ҫǿ���ң�\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

int ask_me()
{
        object who=this_player();
        if (who->query_temp("jinboxunhua")) {
                command("say �Ҳ��Ǹ��������������Ҳ̫�Ǹ��ˡ�");
                return 1;
        }
        command("say �������Ƕ��������Ѱ����Ҹ��ڻ�԰�����˾綾�Ľ�Ѯ����"
                + "���ȥ����ס�����Ϳ����ˡ�");
        who->set_temp("jinboxunhua",1);
        return 1;
}

