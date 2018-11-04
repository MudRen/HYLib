// smith.c

inherit NPC;
inherit F_DEALER;

string ask_me(); //����ask_me
int do_gu(string arg); 
int do_dapi(string arg); 
int do_cuihuo(string arg); 
void reward(object me); 

void create()
{
set_name("����", ({ "tiejiang", "smith" }));//����Ϊ��������
set("title", "�������ϰ�");
set("shen_type", 1);

set("gender", "����" );
set("age", 33);
set("long", "����������ǯ��סһ����ȵ�����Ž�¯�С�\n");

set("combat_exp", 800000);
set("attitude", "friendly");
set("vendor_goods",({//ע���ˣ���߼�����
	    "/clone/weapon/gangdao",
	    "/clone/weapon/changjian",
	    "/clone/weapon/qimeigun",
	    "/clone/weapon/changbian",
	    "/clone/weapon/gangzhang",
	    "/d/city/npc/obj/tiejia",
	    "/clone/box/tuzhu",
}));

set("inquiry", ([ 
"����" : (: ask_me :), 
"job" : (: ask_me :), 
]));

setup();

//carry_object("/clone/misc/cloth")->wear();//Ҳ��Ϊ�˼�����
}

void init()//���嶯��
{
add_action("do_list", "list");
add_action("do_buy", "buy");
add_action("do_gu", "gu"); 
add_action("do_dapi", "dapi"); 
add_action("do_cuihuo", "cuihuo"); 
}

string ask_me() 
{ 
object me = this_player(); 

if (me->query("combat_exp") > 50000) //���EXP�Ƿ����500
return "�����ϸ����δ�������˰ɣ�"; 

if (me->query("qi") < 50) //�����
return "�㻹��Ъ����ɣ�Ҫ�ǳ��������ҿɳе�����"; 

if (me->query_temp("smith/gu")) //�����
return "����ķ��䣬����ô��ĥ��(gu)��"; 

if (me->query_temp("smith/dapi")) 
return "�������������û��(dapi)��"; 


switch(random(3))//���������������
{ 
case 0: 
me->set_temp("smith/gu", 1); 
return "�ã�����ҹ�һ�������(gu)��"; 

case 1: 
me->set_temp("smith/dapi", 1); 
return "�����ɣ�����Ҵ�һ������(dapi)��"; 

case 2:
me->set_temp("smith/cuihuo", 1); 
return "ȥ���Ұ���Щ�ճ�¯�Ĵ�һ�»�(cuihuo)��"; 
} 
} 

int do_gu(string arg) 
{ 
object me = this_player(); 

if (me->is_busy()) 
return notify_fail("��������æ��\n"); 

if (! me->query_temp("smith/gu")) 
{ 
message_vision("$n��͵͵������ķ�������˼���硣" 
"������$N��$n��ȵ����������Ҹ�ʲô��\n", 
this_object(), me); 
return 1; 
} 

message_vision("$n����ķ��ƴ������������$N���˵��˵�ͷ��\n", 
this_object(), me); 
reward(me); 
return 1; 
} 

int do_dapi(string arg) 
{ 
object me = this_player(); 

if (me->is_busy()) 
return notify_fail("��������æ��\n"); 

if (! me->query_temp("smith/dapi")) 
{ 
message_vision("$n���𼸿���������������˵ࡣ" 
"������$N��$n��ȵ������£��Ҹ�ʲô��\n", 
this_object(), me); 
return 1; 
} 

message_vision("$n���Ŵ��ӶԸճ�¯�Ļ��ȵ����������ô��ţ�" 
"$N���š���һ��������ȥ��Щ���⡣\n", 
this_object(), me); 
reward(me); 
return 1; 
} 

int do_cuihuo(string arg) 
{ 
object me = this_player(); 

if (me->is_busy()) 
return notify_fail("��������æ��\n"); 

if (! me->query_temp("smith/cuihuo")) 
{ 
message_vision("$n�ճ���һ������õ����ӣ�" 
"������$N��$n��ȵ������£�����Ҹ㻵�ˡ�\n", 
this_object(),me);
return 1; 
} 

message_vision("$N����ǯ����һ��������ӣ������ˮ" 
"�أ����ꡱ��һ��������ð��\n", 
me); 
reward(me); 
return 1; 
} 

void reward(object me) //�������������佱�ͣ��Ƴ����
{ 
object coin; 

me->delete_temp("smith/gu"); 
me->delete_temp("smith/dapi"); 
me->delete_temp("smith/cuihuo"); 

coin = new("/clone/money/coin"); 
coin->set_amount(20 + random(50)); 
coin->move(this_player()); 
message_vision("$N��$n�������Ǹ���Ĺ�Ǯ��\n", 
this_object(), me); 
if (me->query("combat_exp") < 1000) 
{
me->add("potential", 5); 
me->add("combat_exp", 5 + random(20)); 
} 
me->receive_damage("qi", 30); 
me->start_busy(3); 
} 