inherit NPC;
inherit F_SAVE;

string query_save_file() { return DATA_DIR + "npc/�����"; }
void create()
{

	set_name("�����", ({ "sunerniang", "sunerniang", "sunerniangr" }) );
	set("gender", "����" );
	set("age", 32);
	set("long",
		"��λ�������Ц�����æ����\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");

	set("vendor_goods", ({
		__DIR__"obj/jiu1",
		__DIR__"obj/jiu2",
		__DIR__"obj/jiu3",
	}));
	set("area_name","�㵴ܽ�ؿ�ջ");
	set("area_file","/d/yandang/yuanluo.c");
	 setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/d/hainan/npc/weapon/thin_sword")->wield();
}

int accept_object(object who,object obj)
{
        string bh;

        bh=(string)who->query("banghui");
        if( !bh || bh!=(string)query("banghui"))        {
                if (obj->query("money_id")&&obj->value()>=200)  {
			if(who->query("gender")=="Ů��")
                	tell_object(who,"��������Ц�ݵ�:����ͷ��롣\n");
			else tell_object(who,"��������Ц�ݵ�:����ͷ��롣\n");
                who->set_temp("rent_paid",1);

                return 1;
                }
                else    {
                tell_object(who,"��������ס��Ҫ����������\n");
                return 0;
                }
        }
        if (obj->query("money_id")&&obj->value()>=100)  {
 		if(who->query("gender")=="Ů��")
             	tell_object(who,"��������Ц�ݵ�:��λ���ã�����ͷ��롣\n");
		else tell_object(who,"��������Ц�ݵ�:��λ���֣�����ͷ��롣\n");
        
        who->set_temp("rent_paid",1);
        return 1;
        }
        else    {
                tell_object(who,"��������ͬ�����Ҳ�ø���һ��������˼��˼�ɡ�\n");
                return 0;
        }
}
