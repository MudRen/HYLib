//by cool 98.3.25

inherit NPC;
int study_book();
void create()
{
	set_name("����", ({ "zhu yu","zhu","yu", "guanzhu" }));
	set("title", "������ݹ���");
       set("nick", "��������");
	set("gender", "����");
	set("age", 50);
	set("str", 30);
	set("dex", 26);
	set("long", "�����Ͻ����ӣ�������ϣ�����������վ�����������һ��������\n");
	set("combat_exp", 800000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set_skill("unarmed", 140);
	set_skill("force", 140);
        set_skill("strike", 140);
	set_skill("hammer", 100);
        set_skill("kunlun-zhang", 180);
        set_skill("xuantian-wuji", 160);
        set_skill("kunlun-shenfa", 160);
        set_skill("dodge", 140);
	set_skill("parry", 140);
        map_skill("dodge", "kunlun-shenfa");
        map_skill("parry", "kunlun-zhang");
        map_skill("force", "xuantian-wuji");
        map_skill("strike", "kunlun-zhang");
        prepare_skill("strike","kunlun-zhang");
        set("qi", 2500);
	set("max_qi", 2500);
	set("neili", 2500); 
	set("max_neili", 2500);
	set("jiali", 150);
        set("inquiry",  ([
            "����" : "�Ǻǣ���ȥ�����ܹܰɣ����ᰲ����ġ�",
            "����" : "�������䳡���������ģ���ȥ�����ɡ�",
            "ѧϰ" : (: study_book :),
        ]));
	setup();
        carry_object("clone/cloth/cloth")->wear();
}

void init()
{
     object ob;
     ::init();

     if (interactive(ob = this_player()) && !is_fighting() && !wizardp(ob)){
        if((int)ob->query("combat_exp") > 50000){ 
            command("say �ף�������ô���������ģ���ȥ��ȥ�� \n");
            message_vision("$Nһ���ƴ���$n���ϣ�ֻ��$p��ž~~����һ��������һ���������ӡֱ���˳�ȥ��\n", this_object(), ob);
            ob->move("/d/wuguan/dayuan2");
            command("say ��һ���и����ã��������Դ����£������Ϸ�ʽ��");
            tell_room(environment(ob), "ֻ������~~��һ����У�һ��"+ob->name()+"����ݴ������˹��������ϴ��Ÿ����İ���ӡ��\n", ({ ob }));
            }
         if((int)ob->query_condition("killer")){        
            command("say �㾹�������ɱ�ˣ�\n");
            command("club "+ob->query("id"));
            ob->unconcious();
            } 
         }

}

int study_book()
{
       object me, ob;

       me = this_object();
       ob = this_player();
       if (!me->query_temp("book_get")) {
       command("pat" +ob->query("id"));
       command("say �鷿����Щ�ҳ������飬��ȥ����������û���Լ���Ҫ�ġ�");
       ob->set_temp("wg_study",1);
       }
       else message_vision("$N���Ǹ��ù�һ���������������Ǳ��ɣ�\n", this_player());

       return 1;
}
