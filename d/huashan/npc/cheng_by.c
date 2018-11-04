// NPC: /d/huashan/npc/cheng_by.c
// Date: Look 99/03/25

inherit NPC;

void create()
{
        set_name("�ɲ���",({"cheng buyou", "cheng", "buyou" }));
        set("title","��ɽ�ɵ�ʮ�������ڴ����");
        set("nickname","������");
        set("long", "է����ȥֻ������һ��ƽ���İ��ӣ���Ŀ���׶���ˡ�\n");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        
        set("max_qi",2800);
        set("qi", 2800);
        set("max_jing", 3400);
        set("jing",3400);
        set("eff_jingli", 1700);
        set("jingli", 1700);
        set("max_neili", 9500);
        set("neili", 9500);
        set("jiali", 50);
        set("combat_exp", 800000);
        set("score", 30000);
        set("chat_chance_combat",40);
        set("chat_msg_combat", ({
        (: perform_action, "strike.wuji" :),
        (: perform_action, "sword.kuangfeng" :),
        }));
        set_skill("strike", 140);
        set_skill("hunyuan-zhang", 140);
set_skill("huashan-neigong",  200);
        set_skill("sword",  140);
        set_skill("dodge",  140);
        set_skill("force",  140);
        set_skill("parry",  140);
        set_skill("zixia-shengong", 100);
        set_skill("kuangfeng-jian",  260);
        set_skill("huashan-shenfa",  160);

        map_skill("dodge", "huashan-shenfa");
        map_skill("force","zixia-shengong");
        map_skill("sword","kuangfeng-jian");
        map_skill("parry","huashan-jianfa");
        map_skill("strike","hunyuan-zhang");
        prepare_skill("strike","hunyuan-zhang");
        create_family("��ɽ��",13,"����");

        setup();
	 carry_object("clone/weapon/gangjian")->wield();
	 carry_object("clone/misc/cloth")->wear();
}

void init()
{
        object me, ob;
        ::init();

        ob = this_player();
        me = this_object();

        if (interactive(ob) && !environment(ob)->query("no_fight"))
        {
                       command("say �ҽ����ҽ��ڽ���,ֻ����������\n");
                       me->set_leader(ob);
                       remove_call_out("kill_ob");
                       call_out("kill_ob", 1, ob); 
        }
}
