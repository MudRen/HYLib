// oldman.c

inherit NPC;

string ask_baobei();

void create()
{
        set_name("Ф��ͷ", ({"xiao laotou", "laotou" ,"xiao","oldman","man"}) );
        set("gender", "����" );
        set("age", 65);
        set("long", "����ɫ�ڻƣ������������ƣ�һ��������˪�����ӡ�\n");

        set_skill("unarmed", 50);
        set_skill("dodge", 30);
        set_skill("parry", 40);
        set("combat_exp", 2300);
	set("shen_type", 0);
        set("str", 20);
        set("dex", 15);
        set("con", 20);
        set("int", 20);
        set("attitude","friendly");
	set("unique", 1);

        set("inquiry", ([
                "��" : "�����ˣ��ȽŲ������ˣ����ұ��˰ɡ���\n",
                "����" : "��˵����ѩɽ��������������ס�ĵط���ǧ��Ҫȥ������һ��������С����û�ˡ�\n",
                "ѩɽ����" : "��˵����������ı�����ɽ������Щ���ǣ���붼��ȥѰ���ġ�\n",
                "����" : (: ask_baobei :),
        ]));
        setup();
        set("chat_chance", 2);
        set("chat_msg", ({
		"Ф��ͷҡͷ���Ե����ź��٣��Ե���Ȼ�Եá�\n",
                "Ф��ͷ��ɳ�Ƶͳ������������������������Ҫ���ˣ���Ҫ�޸�����~~~��\n",
        }) );
 carry_object("/clone/misc/cloth")->wear();
//        carry_object(ARMOR_D("pipao"))->wear();
//        carry_object(BINGQI_D("huqin"))->wield();
}

 string ask_baobei()
{
	object me=this_player();
        me->set_temp("baobei_ask",1); 
        return  "��λ"+RANK_D->query_respect(me)+"Ҳ��ȥѰ��ô����......�����ɣ����ҽ�������Ҳ����Ե��������������ɽ���ߣ���ȥ��������Ҫ�����ˡ�\n������˵����������ʲô�¿ɱ����ҡ�\n" ;
}