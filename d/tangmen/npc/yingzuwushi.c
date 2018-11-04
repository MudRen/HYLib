// yingzuwushi.c ������ʿ

inherit NPC;

void create()
{
        set_name("ӥ����ʿ", ({ "yingzu wushi", "wushi" }));
        set("long", 
                "�������ž���ѵ������ʿ���������ŵ��ػ���\n"
                "��������ô����ţ���ɱ���ۣ�\n");
        set("gender", "����");
        set("age", 22);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        
        set("max_qi", 1000);
        set("max_jing", 800);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 30);

        set("combat_exp", 40000);
        set("score", 8500);

        set_skill("force", 60);
        set_skill("biyun-xinfa", 60);
        set_skill("dodge", 70);
        set_skill("qiulinshiye", 50);
        set_skill("strike", 60);
        set_skill("biye-wu", 60);
        set_skill("parry", 60);
        set_skill("sword", 60);
        set_skill("wuzhan-mei", 40);
        

        map_skill("force", "biyun-xinfa");
        map_skill("dodge", "qiulinshiye");
        map_skill("strike", "biye-wu");
        map_skill("parry", "wuzhan-mei");
        map_skill("sword", "wuzhan-mei");

        create_family("����", 9, "����");
        set("class", "tangmen");

        setup();
        carry_object("/d/tangmen/obj/changjian")->wield();
        carry_object("/d/tangmen/obj/suozijia")->wear();
}


void init()
{
	object me, ob;
	mapping fam;

	::init();

	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight")

	&& ( (fam = ob->query("family")) && fam["family_name"] != "����" ) )
	{
		if( !ob->query_temp("warned") ) {
			command("say ����������������㴳��ģ���\n");
			command("say �����뿪������ɱ���㣡\n");
			ob->set_temp("warned", 1);
		}
		else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
		else {
			command("say �󵨿�ͽ�����Ҵ����������������ң�����\n");
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}       

}