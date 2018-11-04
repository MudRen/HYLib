// account.c

#include <ansi.h>

inherit ITEM;       // /std/item

int do_save(string);
int do_load(string);
void reset_balance(object);

void create()
{
        set_name("Ӣ�ۿ�", ({ "credit card","credit","card" }) );
        set("unit", "��");
        set("long",@LONG
���Ǻ���II������ͨ�õ���ʽ���ÿ��������¼�����������е�
�������Ʊ��ܣ���ʧ����Ը���
        deposit   <amount> <money_type>     ��Ǯ
        takeout   <amount> <money_type>     ȡǮ
                     ������  ����һ��
        checkcard                          ����
LONG
        );
        if( clonep() ){
                   set("owner_id",this_player()->query("id"));
                set_default_object(__FILE__);
        }
        set("no_put", 1);
        set("no_get", 1);   
        set("no_sell", 1);   
        set("no_give", 1);   
        set("no_drop", 1);   
        seteuid(getuid());
}

void init()
{
        if( !environment()->is_character())  destruct(this_object());
        else{
                add_action("do_save", "deposit");
                add_action("do_load", "takeout");
                add_action("do_info", "checkcard");
        }
}

int query_autoload(){ return 1; }

int do_save(string arg)
{
        int amount;
        string money;
        object money_ob,me,coin,silver,gold,cash,tencash;

        if (!arg) return 0;
        if (arg=="all")
        return notify_fail("��˵����Ҫ��ʲô��\n");

        me=this_player();
        if (me->is_busy())
        return notify_fail("����æ���ء�\n");
        me->start_busy(1);
        if (2<1)
        {
            coin=present("coin_money",me);
            silver=present("silver_money",me);
            gold=present("gold_money",me);
            cash=present("thousand-cash_money",me);
            tencash=present("ten-thousand-cash",me);
            amount=0;
            if (coin){
              amount+=coin->value();
              destruct(coin);
            }
            if (silver){
              amount+=silver->value();
              destruct(silver);
            }
            if (gold){
              amount+=gold->value();
              destruct(gold);
            }
            if (cash){
              amount+=cash->value();
              destruct(cash);
            }
            if (tencash){
              amount+=tencash->value();
              destruct(tencash);
            }

            me->add("balance",amount);
        }
        else
        {
            if (sscanf(arg,"%d %s",amount,money)!=2)
            {
               amount=-1;
               money=arg;
            }
            else if ( amount < 1 )
                return notify_fail("���Ҽ�������Ҫһ����λ��\n");
            money_ob=present(money+"_money",me);
                if ( amount > 1000 )
                return notify_fail("���Ҽ���һ�β��ܳ���1000��\n");
            if (!money_ob) return notify_fail("������û�����ֻ��ҡ�\n");
            if (amount==-1)
            {
                amount=money_ob->query_amount();
                if (!amount)
                        return notify_fail("������û�����ֻ��ҡ�\n");
            }
            else if( money_ob->query_amount() < amount )
                return notify_fail("������û���Ƕ�"+money_ob->query("name")+"��\n");
            money_ob->add_amount(-amount);
            me->add("balance",money_ob->query("base_value")*amount);
            if (!money_ob->query_amount()) destruct(money_ob);
        }
        write("OK.\n");
        reset_balance(me);
        return 1;
}

int do_load(string arg)
{
        int amount,bv,rich,old=0,tm=0,tmm=0;
        string money;
        object money_ob,me;

        if (!arg) return 0;
        me=this_player();
        if (me->is_busy())
        return notify_fail("����æ���ء�\n");
        me->start_busy(1);

        if (sscanf(arg,"%d %s",amount,money)!=2)
        {
                amount=-1;
                money=arg;
        }
        
        rich=me->query("balance");
        if (!rich) return notify_fail("���ڱ�����û���κδ��!\n");
 if ( amount < 1 )
 return notify_fail("���Ҽ�������Ҫһ����λ��\n");
 if ( amount > 1000 )
 return notify_fail("���Ҽ���һ�β��ܳ���1000��\n");

        money_ob=present(money+"_money",me);
        if (!money_ob)
        {
                if(file_size("/clone/money/"+money+".c")<0) return notify_fail("û�����ֻ���!\n");
                money_ob=new("/clone/money/"+money);
                money_ob->move(me);
                old=-1;
        }
        bv = money_ob->query("base_value");
        if (amount==-1) amount=rich/bv;
        else if( rich < amount*bv + 100 )
              
{
   write("����ʺ���û���Ƕ�"+money_ob->query("name") + "!\n");
  money_ob->add_amount(old);     
       return 1;
} 
 if ( amount < 1 )
 return notify_fail("���Ҽ�������Ҫһ����λ��\n");
 if ( amount > 1000 )
 return notify_fail("���Ҽ���һ�β��ܳ���1000��\n");

       if(amount*bv < 0)  
            {
            money_ob->add_amount(old);
               write("�㲻ҪթƭŶ?
\n");
        return 1;
}
        me->add("balance",-amount*bv-100);
      /*  tm = (int)(amount+old-(int)(amount*0.2));
        tmm = (int)tm;*/
        money_ob->add_amount(amount+old);
        write("OK.\n");
        reset_balance(me);
        return 1;
}

int do_info(string arg)
{
        int rich;
object me=this_player();
        rich=this_player()->query("balance");
        if (me->is_busy())
        return notify_fail("����æ���ء�\n");
        me->start_busy(1);

        if (!rich)        write("Ŀǰ, ����������û���κδ��!\n");
        else
        {
                write("Ŀǰ, ������������:\n");
                if (rich/10000)
                write( chinese_number(rich/10000) +"���ƽ�");
                rich=rich%10000;
                if (rich/100)   write(chinese_number(rich/100)+"������");
                rich=rich%100;
                if (rich)       write(chinese_number(rich) + "��Ǯ");
                write("\n");
        }
        return 1;
}

void reset_balance(object me)
{
    int allowed=me->query("combat_exp");
    int removed_gold;
    string myid=me->query("id");
    string NPCNAME="������";
        if (me->is_busy())
        return notify_fail("����æ���ء�\n");
        me->start_busy(1);

    if(allowed<1000) allowed=1000;
    if(allowed>100000) allowed=100000;
    allowed *= 2500;//each year can have 250 gold, range 250-25000. 
    if( (me->query("balance")) > allowed){
        me->set("balance_old", me->query("balance"));
        me->set("balance", allowed);
        removed_gold = (me->query("balance_old") - me->query("balance"))/10000;
        log_file("MONEY_RESET", ctime( time() )+"���������ս���"+me->query("name")+"("+me->query("id")+")"+removed_gold+"���ƽ�\n");
        tell_object(me, GRN+NPCNAME+"����Ķ�������˵����"+RANK_D->query_respect(me)+
           "���⡢���治֪��ô˵�Ǻã�����\n"NOR);
        tell_object(me, GRN+NPCNAME+"����Ķ�������˵����"+
           "����κ��������ǰ���참���������ϵĻƽ���·������\n"NOR);
        tell_object(me, GRN+NPCNAME+"����Ķ�������˵����"+
        "���������°����ϱ�⣬���ϵ�Ǯ��ȫ���乫�ˣ�����\n"NOR);
    }
}

string query_destruct_msg()
{ 
   return HIB+"�㿴��һ����ɫ��Ƭ�����������������в����ˣ�����\n"+NOR;
}
