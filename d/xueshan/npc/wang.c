// wang.c

inherit NPC;

string ask_gongjv();

void create()
{
        set_name("������", ({"wang sanli", "wang" ,"sanli"}) );
        set("gender", "����" );
        set("age", 35);
        set("long", "һ��ǿ׳�Ĵ󺺣������ĸ첲��֪��������С�����ܴ�������Զ�������ķ����ҡ�\n");

        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set("combat_exp", 20000);
	set("shen_type", 1);
        set("str", 30);
        set("dex", 30);
        set("con", 25);
        set("int", 20);
        set("attitude","friendly");
	set("unique", 1);

        set("inquiry", ([
                "Ф��ͷ" : (: ask_gongjv :),
        ]));
        set("gongjv_count", 2);
        setup();
        set("chat_chance", 1);
        set("chat_msg", ({
		"�����������������������ǡ���ʯ��ľ̿����һ��Ϳ���ȼ�ձ�ը����ÿ���Ŷ�������أ���\n",
                "������������ɫʯͷ��ϸ����˵����������֣�����ô�ܺ�������һ���أ���\n",
                "������̾���������˼ҵĺ���ֻ����ľͷ��ʯƬ��д�֣�Ҫ�����ֱ��˵Ŀ���д�ֵĶ����ͺ��ˡ���\n",
                "��������Ū��Щ��Ƭ�;����������Ƭ̫������ֲ��ñ��棬��������һ���¶�������\n",
                "��������˼�������𾭶����ֳ��ģ��治���㡣Ҫ��������һ�γ����ܶ����أ���\n",
        }) );
carry_object("/clone/misc/cloth")->wear();
//        carry_object(ARMOR_D("pipao"))->wear();
}

 string ask_gongjv()
{
	object me,tool1,tool2;
	me=this_player();

	if (me->query_temp("baobei_ask")){
          if (query("gongjv_count") < 1){ 
	   return "�������ʵ���Ф��ͷ�Ĺ��߰ɣ��ո��Ѿ����������ˣ����������";}
    tool1=new(__DIR__"obj/dingxie");     
    tool2=new(__DIR__"obj/binggao");
	tool1->move(me);
	tool2->move(me);
        add("gongjv_count", -2);
        return  "����㲻�������Ҳ�����ˡ��������������������ߣ���ȥ�ɡ�
������������һ˫��Ь��
������������һ�ѱ��䡣";
	}
}
