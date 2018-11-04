// npc: shidao.c
// Jay 3/26/96
#include <ansi.h>
inherit NPC;
string ask_met();
void create()
{
	set_name("�̼�", ({ "shi jia"}) );
	set("nickname", HIY "��" NOR );
	set("gender", "����" );
	set("age", 40);
	set("long", 	
		"��ͷ�ϰ��ź첼ͷ��һϮ�����ۣ�û��һ˿���塣\n");
	set("str", 25);
	set("dex", 20);
        set("no_get",1);
	set("con", 17);
	set("int", 30);
        set_temp("no_kill",1);
	set("shen_type", 0);
	set("max_neli",500);
	set("jiali",50);

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("force",150);
	set_skill("sword",150);
	set_skill("parry",90);
	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage",150);

	set("combat_exp", 2500000);
	set("score",0);
	
	set("attitude", "peaceful");
        
	set("inquiry", ([
		"����"  : "��Ҫ��һ���Լ��ļ�����\n",
		"ԭ��"  : "���׿��ú�˿���񣬺��׽�ĸ��ǧ����ľ����Ч������һ����\n",
	    "����"  :  (: ask_met() :),
	]) );

	setup();

	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	::init();
	add_action("do_zhu","zhu");
}


int accept_object(object who, object ob)
{	
	if((who->query("jia/make")) ){
		say("�̼�һ��ãȻ�����Ѿ��м�����ļ����ˣ�������ʲô���ѵ�������ô��\n");
		return 0;
	}

	switch ((string)ob->query("id") ) 
	{
		case "shen mu": 
			who->add_temp("shenmu",1);
			break;
		case "jin mu":
			who->add_temp("jinmu",1);
			break;
		case "han zhu": 
			who->add_temp("hanzhu",1);
			break;
		default :
			message("vision","����ʲô���ⲻ������������£�",who);
			return 0;
	}
	who->set_temp("m_jia",1);
	message("vision","�̼׵�ͷ������һ�����е�"+(string)ob->query("name")+
			"���˵�ͷ˵��\n", who);
	message("vision","���������������ھͿ�ʼ����\n", who);
	write("����λ"+RANK_D->query_respect(who)+"����ļ��������ְɣ�(zhu ���µ����� Ӣ�Ĵ���)\n");
	return 1;

}

int do_zhu(string arg)
{
	string o_name,id,w_name;
	object blade,make_time;   //���ɵ��������
	object me;
	me = this_player();
	if(!(me->query_temp("m_jia")) )
		return notify_fail("ʲô?\n");
	me->delete_temp("m_jia");

	if((me->query("jia/make")) ){
		say("�̼�һ��ãȻ�����Ѿ��м�����ļ����ˣ�������ʲô���ѵ�������ô��\n");
		return 0;
	}
	if( !arg )
		return notify_fail("�̼������˵����ü��µ����Ƽ����ź��ڶ���˵��\n");

	sscanf(arg ,"%s %s" ,w_name ,id);
	if(!w_name||!id)
		return notify_fail("ʲô?(ʹ��zhu ���µ����� Ӣ�Ĵ���\n)");
	if(me->query_temp("shenmu") ) o_name="ǧ����ľ";
	if(me->query_temp("jinmu") )   o_name="���׽�ĸ";
	if(me->query_temp("hanzhu") )   o_name="��˿����";
	make_time=NATURE_D->game_time();
	message_vision(me->name()+"������һ�ᣬ���̼�����˵�˼��仰���̼׵��˵�ͷ��˵���ðɣ�\n",me );
	message_vision("\n�̼׻ع���ת������һ���޴�Ļ�¯���Ķ�����ȼ�������ܵĴ��˵����ʼ��\n",me );
	message_vision(BLU "$N˫����סһ���޴���������͵���¯�н�������������"+o_name+"��ȥ��\n" NOR,me);
	message_vision(RED "ֻ�������һ�����죬��ͷ��"+o_name+"ճ����һ��\n" NOR,me );
	message_vision(YEL "$Nֻ��������һ�ȣ������ѪҺ�ƺ���������������\n" NOR,me);
	message_vision(HIM "һ��Ѫ�����������������ԴԴ���ϵ���¯�е�"+o_name+"ӿȥ��\n" NOR,me );
	if( (me->query("qi"))<(me->query("max_qi")) || (me->query("jing"))<(me->query("max_jing")) || (me->query("neili"))<(me->query("max_neili")) )
	{
		message_vision(HIR "ͻȻ$N������Ѫһ��ӿ��һ�������Ӳ������������� \n" NOR, me);
		me->set("neili",0);
		me->unconcious();
		return 1;
	}
	message_vision(HIR "ֻ������һ�����죬һ�����´�¯��ٿȻԾ�𡣻���һ������͵���$N��ǰ�ط�������\n" NOR,me );

	me->set("qi",10);
	me->set("jing",10);
	me->set("neili",0);

        w_name = replace_string(w_name, "$BLK$", BLK);
        w_name = replace_string(w_name, "$RED$", RED);
        w_name = replace_string(w_name, "$GRN$", GRN);
        w_name = replace_string(w_name, "$YEL$", YEL);
        w_name = replace_string(w_name, "$BLU$", BLU);
        w_name = replace_string(w_name, "$MAG$", MAG);
        w_name = replace_string(w_name, "$CYN$", CYN);
        w_name = replace_string(w_name, "$WHT$", WHT);
        w_name = replace_string(w_name, "$HIR$", HIR);
        w_name = replace_string(w_name, "$HIG$", HIG);
        w_name = replace_string(w_name, "$HIY$", HIY);
        w_name = replace_string(w_name, "$HIB$", HIB);
        w_name = replace_string(w_name, "$HIM$", HIM);
        w_name = replace_string(w_name, "$HIC$", HIC);
        w_name = replace_string(w_name, "$HIW$", HIW);
        w_name = replace_string(w_name, "$NOR$", NOR);

	me->set("jia/make",1);		//����������ֹ����ı�־		
	me->set("jia/name",w_name +NOR);	//����������
	me->set("jia/id",id);		//�����Ĵ���
	me->set("jia/lv",1);    	//�����ȼ�
	me->set("jia/or",o_name);	//��¼����ԭ��
	me->set("jia/value",0);	      	//��¼�����������еĵ���	
	me->set("jia/time",make_time);
	me->set("jia/type","��");

	blade=new(__DIR__"jia",1);	//�����¼�
	blade->move(this_player());
	message_vision("�̼�������ϣ����Ű߰�Ѫ������Щ���ֵľ޼ף�˵��\n�ס����ѡ����ɡ������̼׵����񡣡���Ҳ������ˡ�������\n",me );
	say("�̼׼��ѵ�˵���ס����������պã��Ҹ����ˡ�����\n");
	message_vision("�̼�˵�ꡣٿ�ı㲻���ˡ�\n",me);
	this_object()->die();
	return 1;
}

string ask_met() 
{ 
	object weapon;
	object gold;
	object *inv;
	int i;
        object me = this_player(); 
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++) {
        if((int)(inv[i]->query("armor_prop")&&inv[i]->query("ownmake") )  )
        return "�����ϲ����л�����"; 


        if(me->is_busy())
        return "����һ��������û����ɡ�";

        gold = present("gold_money", this_player());
        if( !gold) return "������û�н��ӡ�";

        if((int) gold->query_amount() < 101)
        return "������û����һ�������ӡ�";

	if (me->query("jia/make")) {
        weapon = new(__DIR__"jia",1);
	weapon->move(me);
        gold->add_amount(-100);
        me->start_busy(5);
        return "���ˣ��޺��ˡ�";
		}
else return "�����������"; 
}
}