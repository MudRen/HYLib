// gaohehui.c �ߺͻ�

inherit NPC;
inherit F_DEALER;
string ask_me();

int do_mo(string arg); 
int do_fenyao(string arg); 
int do_zhengli(string arg); 
void reward(object me); 

void create()
{
	set_name("�ߺͻ�", ({ "gao hehui", "gao" }));
	set("per", 29);
	set("no_get",1);
	set("str", 20);
	set("gender", "Ů��");
	set("age", 22);
            set("title", "��ҽ");
	set("long", "������ҽ���ҵĳ�Ů��\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/clone/misc/jinchuang",
		"/clone/misc/yangjing",
		"/clone/misc/wuchangdan",
		"/clone/misc/zhujingchan",
		"/clone/misc/dust",
		"/d/shenlong/obj/xionghuang",
	}));
        set("inquiry", ([
                "����" : (: ask_me :),
                "job"  : (: ask_me :),
        ]));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
        add_action("do_mo", "moyao"); 
        add_action("do_fenyao", "fenyao"); 
        add_action("do_zhengli", "zhengli"); 
}

string ask_me() 
{ 
object me = this_player(); 

if(me->query("family/family_name")!="����������")
return "����˭�����Ҳ���ʶ��!";

 if (me->query("qi") < 30) 
return "�㻹��Ъ����ɣ� ������ȥ��������Ҫ���˸�������"; 

if (me->query_temp("smith/mo")) //�����
return "��������ĥҩȥ����(moyao)��"; 

if (me->query_temp("smith/fenyao")) 
return "�з�ҩ�����û��(fenyao)��"; 

if (me->query_temp("smith/zhengli")) 
return "������������û��(zhengli)��"; 

switch(random(3))//���������������
{ 
case 0: 
me->set_temp("smith/mo", 6+random(11)); 
return "�ðɣ������ĥһ��ҩ(moyao)��"; 

case 1: 
me->set_temp("smith/fenyao", 6+random(11)); 
return "�����ɣ�����ҷ�һ��ҩ(fenyao)��"; 

case 2:
me->set_temp("smith/zhengli", 6+random(11)); 
return "����ҩ��̫�����ˣ����������һ��(zhengli)��"; 
}
return "��ȥ���°�!!"; 
}
 
int do_mo(string arg) 
{ 
object me = this_player(); 

if (me->is_busy()) 
return notify_fail("��������æ��\n"); 

if (! me->query_temp("smith/mo")) 
{ 
message_vision("$n����ҩ����׼��ĥҩʱ��" 
"������$N��$n��ȵ���˭�����������Ҹ�ġ�\n", 
this_object(), me); 
return 1; 
} 

if ((int)me->query_temp("smith/mo") > 1) 
{
message_vision("$n����ҩ�ĸ����������ĥ��������$N���˵��˵�ͷ��\n", 
this_object(), me); 
me->start_busy(1);
me->add_temp("smith/mo",-1);
} else reward(me); 
return 1; 
} 

int do_fenyao(string arg) 
{ 
object me = this_player(); 

if (me->is_busy()) 
return notify_fail("��������æ��\n"); 

if (! me->query_temp("smith/fenyao")) 
{ 
message_vision("$n���ҵ�ץ�˼���ҩ�����С�" 
"ֻ����$N��$n��ȵ������£��������Ҹ�ʲô��\n", 
this_object(), me); 
return 1; 
} 

if ((int)me->query_temp("smith/fenyao") > 1) 
{
message_vision("$n��ϸ�������е�ҩ�Ŀ�ʼ��ҩ��" 
"$N���š���һ��������ȥ��Щ���⡣\n", 
this_object(), me); 
me->add_temp("smith/fenyao",-1);
me->start_busy(1);
}
else reward(me); 
return 1; 
} 

int do_zhengli(string arg) 
{ 
object me = this_player(); 

if (me->is_busy()) 
return notify_fail("��������æ��\n"); 

if (! me->query_temp("smith/zhengli")) 
{ 
message_vision("$n��$N��ע������ҩƷ�ʹ����������ﶪ��" 
"������$N��$n��ȵ������뺦���˰�����������ҷ��¡�\n", 
this_object(),me);
return 1; 
} 

if ((int)me->query_temp("smith/zhengli") > 1) 
{
message_vision("$N�鿪ҩ����ҩǩ��ҩƷ����źá�\n", 
me); 
me->start_busy(1);
me->add_temp("smith/zhengli",-1);
} else reward(me);

return 1; 
} 

void reward(object me) //�������������佱�ͣ��Ƴ����
{ 
object coin; 
int exp,pot;
exp=15+random(25);
pot=10+random(10);
me->delete_temp("smith/mo"); 
me->delete_temp("smith/fenyao"); 
me->delete_temp("smith/zhengli"); 

coin = new("/clone/money/coin"); 
coin->set_amount(20 + random(50)); 
coin->move(this_player()); 
message_vision("$N��$n�������Ǹ���Ĺ�Ǯ��\n", 
this_object(), me); 
me->add("potential", pot); 
me->add("combat_exp", exp); 
me->receive_damage("qi", me->query("qi")/20); 
me->receive_damage("jing", me->query("jing")/20); 
me->start_busy(1); 
tell_object(me,"�㱻������\n"+chinese_number(exp)+"��ʵս����\n"
		+chinese_number(pot)+"��Ǳ��\n");
} 