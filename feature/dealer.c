// dealer.c ����
// This is a inheritable object.
// Each dealer should support buy, sell, list, value 4 commands
// Modify by Yu Jue 98-8-5

#include <dbase.h>

static mapping armor = ([]);
static mapping book = ([]);
static mapping misc = ([]);
static mapping weapon = ([]);

int query_goods_value(object goods, string method)
{
        object me = this_player();
        int value, trade_level;

        value = goods->query("value");
        trade_level = me->query_skill("trade", 1) / 5;
        if (trade_level > 40) trade_level = 40;
        if (method == "buy")
                value = value * (140 - trade_level) / 100;
        else if (method == "sell" || method == "value")
                value = value * (50 + trade_level) / 100;
        return value;
}

string is_vendor_good(string arg)
{
        string *goods;
        int i;

        if (arrayp(goods = query("vendor_goods"))) 
                for (i = 0; i < sizeof(goods); i++) 
                        if (goods[i]->id(arg)) return goods[i];
        return "";
}

int do_value(string arg)
{
        object ob;
        int value;

        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("��Ҫ��ʲô�ۣ�\n");

        if (ob->query("money_id"))
                return notify_fail("��û�ù�Ǯ����\n");

        value = query_goods_value(ob, "value");
        if (value < 30)
                write(ob->name() + "һ�Ĳ�ֵ��\n");
        else 
                write(ob->name() + "ֵ" + MONEY_D->price_str(value) + "��\n");
        return 1;
}

int do_sell(string arg)
{
        object ob;
         object me = this_player();
        int value, value1, improve;
        object nob;
        string my_id;
        int amount;
        int res;
        int max_count;

        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ء�\n");
        if (!arg || !(ob = present(arg, me)))
                return notify_fail("��Ҫ��ʲô��\n");


        if (ob->query("money_id"))
                return notify_fail("��������Ǯ����\n");

	if (stringp(ob->query("no_drop")))
		return notify_fail("����������������\n");

//        if (ob->query("no_drop") || ob->query("no_get"))
//                return notify_fail("������������������������\n");

        if (ob->query("ownmake"))
                return notify_fail("�����ı����ҿ�����\n");

        if (query_temp("busy"))
                return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

        if (is_vendor_good(arg) != "") 
                return notify_fail("��������ò��ã�\n");


        value = ob->query("value");
        value1 = query_goods_value(ob, "sell");
        if (value < 30)
                write(ob->name() + "һ�Ĳ�ֵ��\n");
        else if (value >= 1000000)
                write(ob->name() + "���ǿ�����\n");
        else {
         if (value < 200 || ob->query_amount()
         || ob->query("yaocao")
         || ob->query("food_supply")) {
                        message_vision("$N������һ" + ob->query("unit") + 
                                ob->name() + "��$n��\n", me, this_object());
                        message_vision("$N��$n����һ�ӣ�˵������ô����ֵǮ������Ҳ��������\n",
                                this_object(), ob);
                        destruct(ob);
                } else {
                        if (ob->move(this_object())) {
                                message_vision("$N������һ" + ob->query("unit") + 
                                        ob->name() + "��$n��\n", me, this_object());
                                ob->set("no_get", 1);
                                if (ob->query("armor_type")) armor[base_name(ob)]++;
                                else if (ob->query("skill")) book[base_name(ob)]++;
                                else if (ob->query("weapon_prop")) weapon[base_name(ob)]++;
                                else misc[base_name(ob)]++;
                        }
                        else return notify_fail("��������Ѿ�̫���ˣ���ʱֹͣ�չ���\n");
                }
                MONEY_D->pay_player(me, value1);
                improve = 40 - me->query("pur");
                me->improve_skill("trade", improve / 2 + random(improve));
        }
        return 1;
}

int do_list(string arg)
{
        string *goods;
        mapping ptr;
        object *inv;
        int i, j, flag = 0;

        if (arrayp(goods = query("vendor_goods"))) {
                write("Ŀǰ�������»��\n");
                for (i = 0; i < sizeof(goods); i++)
                        printf("%30-s��%s\n", goods[i]->short(),
                                MONEY_D->price_str(query_goods_value((object)goods[i], "buy")));
                return 1;
        }

        switch (arg) {
                case "armor": arg = "����"; ptr = armor; break;
                case "book": arg = "�鼮"; ptr = book; break;
                case "misc": arg = "����"; ptr = misc; break;
                case "weapon": arg = "����"; ptr = weapon; break;
                default: return notify_fail("���뿴��һ�ֻ���(armor, book, misc, weapon)��\n");
        }

        
        i = sizeof(ptr);
        if (!i)
                return notify_fail("Ŀǰû�п�������"+arg+"��\n");
        
        goods = keys(ptr);
        inv = all_inventory();
        while (i--) {
                j = sizeof(inv);
                while (j--) {
                        reset_eval_cost();
                        if (inv[j]->query("no_get") && goods[i] == base_name(inv[j])) {
                                if (!flag) write("Ŀǰ��������"+arg+"��\n");
                                printf("%-30s ���ۣ�%s\n", inv[j]->short(),
                                        MONEY_D->price_str(query_goods_value(inv[j], "buy") * 6 / 5));
                                flag = 1;
                                break;
                        }
                        if (j<0) map_delete(ptr, goods[i]);
                }
        }
        if (!flag) write("Ŀǰû�п�������"+arg+"��\n");
        return 1;
}

int do_buy(string arg)
{
        int i, val_factor = 5, improve;
        string ob_file;
        object *inv;
        object ob;
        mapping goods;
        int     amount;
        int     value;
	object *obs;
	string  my_id;
        string  start_room;
        object  room;
        mapping room_obmap;

        object me = this_player();

        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ء�\n");

        if (query_temp("busy"))
                return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

        if (!arg) return notify_fail("������ʲô��\n");
        if (! query("carried_goods"))
        {
                if (stringp(start_room = query("startroom")) &&
                    (room = find_object(start_room)) != environment())
                {
                        // I am not in start room.
                        message_vision("$N���һ���������ã�����ô�ܵ�������ˣ���\n"
                                       "˵��ͷҲ���صļ���ææ�������ˡ�\n", this_object());
                        if (! objectp(room) ||
                            ! mapp(room_obmap = room->query_temp("objects")) ||
                            member_array(this_object(), values(room_obmap)) == -1)
                        {
                                destruct(this_object());
                        } else
                                this_object()->move(room);
                        return 1;
                }
        }

        if (sizeof(filter_array(all_inventory(me), (: ! $1->query("equipped") :))) >= 40)
        {
                write("�����ϵĶ���̫���ˣ��ȴ���һ���������ɡ�\n");
                return 1;
        }

        inv = all_inventory();
        i = sizeof(inv);
        if (i)
                while (i--) if (inv[i]->id(arg) && inv[i]->query("no_get")) { ob = inv[i]; val_factor = 6; break; }

        if (!ob) {
                if ((ob_file = is_vendor_good(arg)) == "")
                        return notify_fail("������Ķ���������û�С�\n");
                else ob = new(ob_file);
        }

        if( (int)me->query_encumbrance() + ob->weight()
                > (int)me->query_max_encumbrance() ) 
        return notify_fail( me->name() + ":���Ѿ��ò����˰�!\n");

        switch (MONEY_D->player_pay(me, query_goods_value(ob, "buy") *  val_factor / 5)) {
                case 0:
                        if (val_factor == 5) destruct(ob);
                        return notify_fail("��⵰��һ�ߴ���ȥ��\n");
                case 2:
                        if (val_factor == 5) destruct(ob);
                        return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
                default:
                        if (!ob->move(me)) {
                                if (val_factor == 5) destruct(ob);
                                return 0;
                        }
                        ob->delete("no_get");
                        message_vision("$N��$n����������һ" + ob->query("unit") +
                                ob->name() + "��\n", me, this_object());
                        improve = 40 - me->query("pur");
                        me->improve_skill("trade", improve / 2 + random(improve));
        }
        set_temp("busy", 1);
        call_out("delete_temp", 1, "busy");

        return 1;
}

/*void reset()
{
	int i;
	object *obs;

	obs = all_inventory();
        for (i = 0; i < sizeof(obs); i++)
                if (i >= 100 || obs[i]->query_weight() >= 1000000)
                        destruct(obs[i]);
}
*/