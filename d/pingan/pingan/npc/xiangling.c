#include <ansi.h>
inherit NPC;

#define MAX_PAWN 50
inherit F_VENDOR;
void create()
{
        set_name("����", ({ "xiangxiang" }) );
	set("gender", "Ů��" );
	set("age", 29);
	set("title", "�����ϰ���");
	set("long",
                "�����С������ǧ��¥��������࣬�����Ƴ������˻��ģ�
�ձ�һ�������У�ȢΪ��ʮ�߷�С���š�\n");
        set("combat_exp", 5000);
	set("attitude", "friendly");
	set("per",30);
	set("no_arrest",1);
	set_skill("unarmed",200);
	set_skill("dodge",200);
	setup();

       carry_object("/d/city/obj/flower_shoe")->wear();
       carry_object("/d/city/obj/pink_cloth")->wear();
}
void init()
{
	add_action("do_value", "value");
	add_action("do_pawn", "pawn");
//	add_action("do_sell", "sell");
	add_action("do_redeem", "redeem");
}

string value_string(int value)
{
	if( value < 1 ) value = 1;
	else if( value < 100 )
		return chinese_number(value) + "��Ǯ";
	else
		return chinese_number(value/100) + "��"
			+ (value%100? "��" + chinese_number(value%100) + "��Ǯ": "");
}

void pay_player(object who, int amount)

{
	object ob;
	if( amount < 1 ) amount = 1;
	if( amount/10000 ) {
		ob = new(GOLD_OB);
		ob->set_amount(amount/10000);
		ob->move(who);
		amount %= 10000;
	}
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
	if( amount ) {
		ob = new(COIN_OB);
		ob->set_amount(amount);
		ob->move(who);
	}
}

int do_value(string arg)
{
	object ob;
	int value;

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("��Ҫ��ʲ����Ʒ�����̹��ۣ�\n");

	if( ob->query("money_id") )
		return notify_fail("���ǡ�Ǯ������û������\n");

	value = ob->query("value");
	if( !value ) printf("%sһ�Ĳ�ֵ��\n", ob->query("name"));
	else 
		printf("%s��ֵ%s��\n�����Ҫ�䵱(pawn)�������õ�%s��\n�������(sell)�������õ�%s��\n",
			ob->query("name"), value_string(value),
			value_string(value * 25 / 100), value_string(value * 80 / 100));

	return 1;
}

int do_pawn(string arg)
{
	object ob;
	string term, *terms;
	string data;
	int value, pawn_count, i;
	int rvalue;
	mapping pawn;
	object me;
	me = this_player();
	pawn = me->query("pawn");
	if( !arg || !(ob = present(arg, this_player())) )
	{
	write("��Ŀǰ�䵱����Ʒ�У�\n");
	if( !mapp(pawn) ||   !sizeof(pawn) )
		write("\tû���κε䵱����Ʒ��\n");
	else {
                        terms = keys(pawn);
                        for(i=0; i<sizeof(terms); i++)
                                printf("%-3s��  %-15s  ������%s\n", terms[i], pawn[terms[i]],
			value_string(((int)me->query("vpawn/"+terms[i]))* 3/4));
              }
	return 1;
	}
	if( ob->query("money_id") )	return notify_fail("��Ҫ����Ǯ����\n");
        if( ob->query("equipped") || ob->query("no_drop") )     return notify_fail("�����ɵ����ˣ�\n");
	value = ob->query("value");
	if( !(value/4) ) return notify_fail("������������ֵ�ܶ�Ǯ��\n");
        if( mapp(pawn) && sizeof(pawn))
                {
                        terms = keys(pawn);
                        if(sizeof(terms) > MAX_PAWN)
                        return notify_fail("���ѵ䵱̫����Ʒ�ˡ�\n");
			for(i=0; i<sizeof(terms); i++)	
			{
			pawn_count = i;
                        if(!((int) me->query("vpawn/" + sprintf("%d", i))))
                         break;
                        else pawn_count = i+1;
			}
                }
	else pawn_count = 0;
	term = ob->query("name");
	data = base_name(ob)+ ".c";
	me->set("pawn/"+ sprintf("%d",pawn_count),  term);
	me->set("vpawn/"+sprintf("%d",pawn_count), ob->query("value"));
	me->set("fpawn/"+sprintf("%d",pawn_count), data);
	me->save();
	message_vision("$N�����ϵ�" + ob->query("name") + "�ó����䵱��"
		+ value_string(value * 25 / 100) + "��\n", this_player());

	pay_player(this_player(), value * 25 / 100 );
	destruct(ob);

	return 1;
}

int do_sell(string arg)
{
	object ob;
	int value;

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("��Ҫ����ʲ����Ʒ��\n");

	if( ob->query("money_id") )	return notify_fail("��Ҫ����Ǯ����\n");
	value = ob->query("value");
	if( !value ) return notify_fail("����������ֵǮ��\n");


	message_vision("$N�����ϵ�" + ob->query("name") + "������\n",
		this_player());

	pay_player(this_player(), value  * 80 / 100);
	destruct(ob);

	return 1;
}
void pay_him(object who, int amount)

{
	object ob;
        object cash, tencash, gold, silver, coin;
        tencash = present("tenthousand-cash_money", who);
        cash = present("thousand-cash_money", who);
        gold = present("gold_money",who);
        silver = present("silver_money",who);
        coin = present("coin_money",who);
	if(tencash) destruct(tencash);
        if(cash) destruct(cash);
        if(gold) destruct(gold);
        if(silver) destruct(silver);
        if(coin) destruct(coin);


	if( amount < 1 ) amount = 1;
	if( amount/10000 ) {
		ob = new(GOLD_OB);
		ob->set_amount(amount/10000);
		ob->move(who);
		amount %= 10000;
	}
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
	if( amount ) {
		ob = new(COIN_OB);
		ob->set_amount(amount);
		ob->move(who);
	}
}

int affordable(object me, int amount)
{
        int total;
        object cash, tencash, gold, silver, coin;

        tencash = present("tenthousand-cash_money", me);
        cash = present("thousand-cash_money", me);
        gold = present("gold_money",me);
        silver = present("silver_money",me);
        coin = present("coin_money",me);

        total = 0;
        if( tencash) total += tencash->value();
        if( cash) total += cash->value();
        if( gold ) total += gold->value();
        if( silver ) total += silver->value();
        if( coin ) total += coin->value();

        if( total < amount ) return 0;

        return total;
}
int do_redeem(string arg)
{
        int num;
        int amount;
        string ob_file;
        object ob;
        object me;
        int afford;
        if( !arg || sscanf(arg, "%d", num)!=1 )
                return notify_fail("ָ���ʽ��redeem <��Ʒ���>\n");
        me = this_player();
        amount = (int) me->query("vpawn/" + sprintf("%d", num));
        if( !amount )
                return notify_fail("�������Ʒ�����\n");
        amount = amount * 3 /4;
        if( afford = affordable(me, amount) ) {
                pay_him(me, afford-amount);
                ob_file = me->query("fpawn/"+sprintf("%d",num));
                ob = new(ob_file);
                ob->move(me);
                me->delete("pawn/"+sprintf("%d",num));
                me->delete("vpawn/"+sprintf("%d",num));
                me->delete("fpawn/"+sprintf("%d",num));
		me->save();
                message_vision("$N�����$n��\n", me, ob);
                return 1;
        } else
                return notify_fail("���Ǯ������\n");

}

