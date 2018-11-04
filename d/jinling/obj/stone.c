// cai.c

inherit ITEM;

string* titles = ({
	"��ĥ�ʼ�",
	"����Ѽ��",
	"��縼�˿",
	"����",
	"���Ƿ�",
	"��Ƭ���ײ�",
	"����ţ��",
	"���������˶���",
	"ӣ����ɽҩ",
	"¿�����ײ�",
	"����Ƭ��С�ܲ�",
	"Ѽ���ﺣ��",
	"Ѽ���������",
	"�մĹ�",
	"��Ƭ������Ƭ",
	"����˿���ܶ�˿",
	"�ƾ²˳���",
	"Ѭ�⻨С��",
	"Ѭ��˿",
	"������",
	"�����ͳ��ײ�˿",
	"��������",
	"�����",
});


void create()
{
	int i = random(sizeof(titles));

	set_name(titles[i], ({ "cai", "xiaocai" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ��ʮ�ֿɿڵ�С�ˡ�\n");
		set("unit", "��");
		set("value", 3000);
		set("remaining", 4);
		set("food_supply", 25);
	}
	setup();
}
void init()
{
	add_action("do_eat", "eat");
}


int do_eat(string arg)
{
	int i = random(sizeof(titles));

    if( !this_object()->id(arg) ) return 0;
    if( this_player()->is_busy() )
        return notify_fail("����һ��������û����ɡ�\n");
    if(   (int)this_player()->query("food")
       >= (int)this_player()->max_food_capacity() )
     return notify_fail("���Ѿ���̫���ˣ���Ҳ�Բ����ˡ�\n");

    set("value", 0);
    this_player()->add("food", (int)query("food_supply"));

    if( this_player()->is_fighting() ) this_player()->start_busy(2);

    add("remaining", -1);
	if ( query("remaining") ){
		if ((string)this_player()->query("gender") == "����")	{
   		 message_vision("$N�����������һЩ��������У����̻��ʵس�������\n", this_player());
		} 
		else if ((string)this_player()->query("gender") == "Ů��") {
		message_vision("$Nʮ�����ŵش����������һЩ��������С�\n", this_player());
		}
	}
	else 	{ 
		if ((string)this_player()->query("gender") == "����")	{
   		 message_vision("$N������Ĳ˳��˾��⣬�ٰ��������˸��ɸɾ�����\n",this_player());
		destruct(this_object());
		}
		else if ((string)this_player()->query("gender") == "Ů��") {
		 message_vision("$N�Թ�������Ĳˣ����ó�һ��˿��������ز��˲��졣\n",this_player());
		destruct(this_object());
		}
	}

	return 1;
}

