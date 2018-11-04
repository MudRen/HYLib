//createskill.c
/////////////////////////
//write by maxim@nju_fengxue
//mail address is to see: maxim jiang of bbs.nju.edu.cn
// 1997.12.21
////////////////////////

#include <ansi.h>

inherit F_CLEAN_UP;

#define SHUANGYIN_HAO "\""
#define HEADER_END 16
#define SPE_PRA_LINES 34

// static string *valid_types = ({
 string *valid_types = ({
	"unarmed",
	"sword",
	"blade",
//	"stick",
	"staff",
	"club",
//	"throwing",
//	"force",
//	"parry",
//	"dodge",
//	"magic",
//	"spells",
	"hammer",
//	"move",
//	"array",
	"whip",
//      shaolin skills
        "finger",
        "hand",
        "cuff",
        "claw",
        "strike",
//      "club":     "����",

//added by maxim
//	"music",
//	"piano",
//	"rube",
//	"drum",

//add by cooler
//        "base-ansha",
//        "xiadu",

//add by xxs
//        "spear",
//        "bow",
//        "arrow",
});

string *banned_name=({
          "  ",});

//static string *spe_skill_lvl=({
 string *spe_skill_lvl=({
            "0","12","20","30","40","50","60","80","100",});
//static string *spe_skill_force=({
 string *spe_skill_force=({
                "50","80","100","130","150","180","200","220",
                   });
//static string *spe_skill_unarmeddodge=({
string *spe_skill_unarmeddodge=({
             "10","-10","-20","-30","-50","-60","-80","-90","-100",
                   });
//static string *spe_skill_unarmedparry=({
 string *spe_skill_unarmedparry=({
            "10","-10","-20","-30","-40","-50","-60","-70","-80",
                   });
//static string *spe_skill_weapondodge=({
 string *spe_skill_weapondodge=({
             "20","10","10","5","-5","-5","-10","-10","-10",
                   });
//static string *spe_skill_weaponparry=({
 string *spe_skill_weaponparry=({
            "20","20","10","10","5","5","5","5","5",
                   });

//static mapping spe_skill = ([
 mapping spe_skill = ([
   "action" : ({" "}),
     "force" : ({"10"}),
    "dodge" : ({"10"}),
    "parry": ({"10"}),
    "damage_type" : ({"����"}),
    "lvl" : ({"10"}),
    "skill_name" : ({"��ճ���"}),
    "skill_total_num" : ({"0"}),
    "skill_en_name" : ({" "}),
    "skill_ch_name" : ({" "}),
   ]);
//static int spe_skillnum;;
 int spe_skillnum;
//it store the true name of replaced
//static string spe_skill_name;
 string spe_skill_name;
//it store the basic skill name
//static string spe_skill_basename;
 string spe_skill_basename;

int check_legal_id(string id);
int check_legal_name(string name);
int check_action_name(string yn);
int check_legal_basename(string name);
void skill_init_header(string skill_en_name,string skill_ch_name);
void get_zhaoshi_ch_name(string yn, object ob);
void get_zhaoshi_ch_action(string yn, object ob);
int check_skillnum_exist(object me,string skill_en_name,int skill_num);
void finish_write_skill(object ob);
int check_owner_skill(object me,string skill_en_name);
string get_header_skillchname(string file);
string get_header_skillbasename(string file);

int main(object me, string arg)
{
//1. exp limit,so skill lvl is according to the exp,if exp low,lvl is low
//2. first create the unarmed as a test,and the same will be sword,blade
//etc....
//3. arg is the skillname player want to create
//all create skill will be write as a log file
//so wizard can know what is the player's skill
//ָ���ʽ��createskill foliage_unarmed ��ʽ��
//1)check if the exp is enough to the ��ʽ��
//2)check if the ��ʽ have been enough
//3)ask player to input the skill_spe_name
//4)ask player to input the action
//so let's do it!

int skill_num,skill_num_result;
string skill_en_name,skill_ch_name;
string skill_base_name;

spe_skill_basename="";
spe_skill_name="";
spe_skillnum=0;

if(!arg)
    return notify_fail("ָ���ʽ��creatskill �书�������� �书Ӣ������ �书�������� �ڼ���\n");
if( sscanf(arg, "%s %s %s %d", skill_base_name,skill_en_name,skill_ch_name,skill_num)!=4)
    return notify_fail("ָ���ʽ��creatskill �书�������� �书Ӣ������ �书�������� �ڼ���\n");

//if (!wizardp(me) )
//    return notify_fail("��ϵͳ�ݲ����ţ�������!\n");
//write("to see the skillnum is:"+skill_num+"\n");

skill_en_name=lower_case(skill_en_name);

spe_skill_basename=skill_base_name;

if(check_legal_basename(skill_base_name)==0)
    return notify_fail("������Ļ������ܲ����ڡ�\n");

if(check_legal_id(skill_en_name)==0)
               return 1;             

spe_skill["skill_en_name"]=skill_en_name+"-"+skill_base_name+".c";
spe_skill_name=skill_en_name+"-"+skill_base_name;

//write(spe_skill_name+"\n");
//write(spe_skill_basename+"\n");
//write(spe_skill["skill_en_name"]+"\n");

if(check_legal_name(skill_ch_name)==0)
               return 1;             

spe_skill["skill_ch_name"]=skill_ch_name;

//write(spe_skill["skill_ch_name"]+"\n");

//so player can change the Chinese skill name when he begin to create
//only 1 ��
if( skill_num!=1 
    && get_header_skillchname(spe_skill["skill_en_name"])!=skill_ch_name)
    return notify_fail("������������书���ƺ���ѡ��Ӣ���书������ì�ܡ�\n");

if( skill_num!=1 
    && get_header_skillbasename(spe_skill["skill_en_name"])!=skill_base_name)
    return notify_fail("������Ļ�������������ѡ��Ӣ���书������ì�ܡ�\n");


//here is important
if((int)me->query("skillmaxim")!=0
        && sizeof(keys(me->query("skillmaxim/"))) >3 )
    return notify_fail("�����ֻ�ܴ������ָ߼�����\n");


switch( check_owner_skill(me,spe_skill["skill_en_name"])){
        case 2:
    return notify_fail("��������ڽ������Ѿ����ڣ����޷����д��¡�\n");
       break;
        case 0: //this is right
         break;
        case 1:
    return notify_fail("��Ŀǰֻ���������������ܴ���һ������\n");
        default:
        return notify_fail("�����ʦ��ϵ���������򲻶ԡ�\n");
    }

if(skill_num < 1)
       return notify_fail("����Ҫ�ӵ�һ�п�ʼ������\n");

if((int)me->query("combat_exp") < 9000000)
       return notify_fail("��ľ���ֵ��������\n");

if((int)me->query("combat_exp") < (skill_num-1)*150000+1000000)
       return notify_fail("��ľ���ֵ��������\n");

if((int)me->query_skill(spe_skill_name)!=0
     && (int)me->query_skill(spe_skill_name) < (skill_num-1)*8)
       return notify_fail("���Ѿ��е���ʽ��������������������ǣ�Ȼ���������аɡ��\n");
    
//write("!!!to see skill num is:"+skill_num+"\n");

skill_num_result=(check_skillnum_exist(me,spe_skill["skill_en_name"],skill_num));

//write("see the skill_num:"+skill_num_result);

if(skill_num_result > 1) {
      write("\r�����ʽ�������(��Ҫ��ʱ���ߣ�������Զ�޷�����ȷ����):");
                   }
else if(skill_num_result==1) {
//here always set to 1 if create again
      write("�����ڿ�ʼ����"+skill_ch_name+"("+spe_skill_name+")"+"�ĵ�һ��.\n");
      write("\r�����ʽ�������(��Ҫ��ʱ���ߣ�������Զ�޷�����ȷ����):");
                         }
else 
        return notify_fail("����Ҫ�����������ʽ������\n");

spe_skillnum=skill_num;

//bug have been here,so sad...
if(skill_num==1) {
             rm(SKILL_D(spe_skill["skill_en_name"]));
          //  write("here ???\n");
             skill_init_header(spe_skill["skill_en_name"],skill_ch_name);
                      }
input_to( (: get_zhaoshi_ch_name :), this_player() );
return 1;
}
string get_header_skillchname(string file)
{
string result;

string content,*list;
content=read_file(SKILL_D(file));
if((int)content==0)
       return 0;
list = explode(content, "\n");
if(sizeof(list) < 8)
     return 0;
else {
    if(sscanf(list[7],"// %s",result)!=1) 
               return 0;
    else 
         return result;
  }
return 0;
}
string get_header_skillbasename(string file)
{
string result;

string content,*list;
content=read_file(SKILL_D(file));
if((int)content==0)
 return 0;
list = explode(content, "\n");
if(sizeof(list) < 7)
 return 0;
else {
    if(sscanf(list[6],"// %s",result)!=1) 
               return 0;
    else 
         return result;

  }
return 0;
}

//only the first time be created
void skill_init_header(string skill_en_name,string skill_ch_name)
{

//file header of the skill for each file
string header;
// string header2;
// string *list;
object me;
int i;
string result;

result="";
me=this_player();
header="";

header="// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)\n";
header+="// "+geteuid(me)+"\n";
header+="// "+me->query("name")+"\n";
header+="// "+me->query("title")+"\n";
header+="// "+me->query("combat_exp")+"\n";
header+="// "+me->query("gender")+"\n";
header+="// "+spe_skill_basename+"\n";                  //list[6]
header+="// "+spe_skill["skill_ch_name"]+"\n"; //list[7]
//here seem bug ...not check
for(i=10;i<15;i++)
    header+="\n";
write_file(SKILL_D(skill_en_name),header);
write_file(SKILL_D(skill_en_name),"inherit SKILL;\n");
write_file(SKILL_D(skill_en_name),"\n////////////////////////////////\n");

//here add the first skill string
write_file(SKILL_D(skill_en_name),"\nmapping *action = ({\n");

write_file(SKILL_D(skill_en_name),"\n"+"// ZHAOSHI : 0");
//this is only a id check of it,no other use
//but is important


}
void get_zhaoshi_ch_name(string yn, object ob)
{
 if( yn=="" ) {
      write("\r�����ʽ�������(��Ҫ��ʱ���ߣ�������Զ�޷�����ȷ����):");
        input_to( (: get_zhaoshi_ch_name :), ob );
        return;
       }

//bug here so remove
//input must be ok...or will can't create always.....
/*
 switch(yn[0]){
    case 'E':
    case 'Q':
          return;
        }
*/

 if( !check_legal_name(yn) ) {
        write("��ʽ���ƣ�");
        input_to( (: get_zhaoshi_ch_name :), ob );
        return;
           }
//then get action
//here init the skill ��ʽ
  spe_skill["skill_name"]=yn;

write(HIR"\n�����в��ܳ��ֿ��Ʒ�����Ȼ��ɾ��!\n"NOR);
write("\n����һ�����С����Ĵ򶷣�(����ָ��:����Ҫ�����С�����������!)\n");
write("\n��ǰ���߳������Ƚż��أ�һʽ����ճ�����������ֱ��������С�������������·\n");
write("������һԾ����������һ�С����к�ء���׼С�����ĳ��λбб�̳�һ��\n");

  input_to("get_zhaoshi_ch_action", 1, ob);

}

void get_zhaoshi_ch_action(string yn, object ob)
{
if(check_action_name(yn)==0)
{
 input_to( (: get_zhaoshi_ch_action :), ob );
               return;             
}
if(CHINESE_D->check_length(yn) > 160)
{
 write(HIR"����̫����\n"NOR);
 input_to( (: get_zhaoshi_ch_action :), ob );
 return;
}

if(CHINESE_D->check_control(yn))
{
 write(HIR"����书���������ÿ�����Ԫ��\n"NOR);
 input_to( (: get_zhaoshi_ch_action :), ob );
 return;
}
 if( yn=="" ) {
write(HIR"\n�����в��ܳ��ֿ��Ʒ�����Ȼ��ɾ��!\n"NOR);
write("\nע�⣬һ��Ҫд����������Ȼ�ǷǷ���ʽ���ᱻɾ��)д��󣬿��д���»س���\n");
write("\n����һ�����С����Ĵ򶷣�(����ָ��:����Ҫ�����С�����������!)\n");
write("\n��ǰ���߳������Ƚż��أ�һʽ����ճ�����������ֱ��������С�������������·\n");
write("������һԾ����������һ�С����к�ء���׼С�����ĳ��λбб�̳�һ��\n");
 input_to( (: get_zhaoshi_ch_action :), ob );
 return;
 }

/*
 switch(yn[0]){
    case 'e':
    case 'q':
          return;
        }
*/

//here init the skill ��ʽ
  spe_skill["action"]=yn;
//finish write the file
 finish_write_skill(ob);
ob->set("skillmaxim/"+spe_skill_basename,1);
 if(spe_skillnum==1) {
      ob->set_skill(spe_skill_name,1);
       }

 log_file( "CREATESKILL", sprintf("%s(%s) %s(%s): %d (%s)\n",
 ob->query("name"),
 ob->query("id"),
  spe_skill["skill_ch_name"],
 spe_skill_name,
  spe_skillnum,
  ctime(time()) ) );

//here to Chinese ==
CHINESE_D->add_translate(spe_skill_name,spe_skill["skill_ch_name"]);


}

//first header
//then action
//then 35 lines of practice or other thing

//here should determain the file is: over wirte or appetine something
void finish_write_skill(object ob)
{
string action;
string file,*list;
string content;
int before_skillnum,i;
string *list2;
string header2;
string result;

header2="";
result="";
content="";
action="";
//spe_skill["force"]=spe_skill_force[spe_skillnum-1];
spe_skill["force"]=30+spe_skillnum*30;

switch(spe_skill_basename){
  case "unarmed":
spe_skill["damage_type"]="����";
  break;
  case "sword":
  case "spear":
spe_skill["damage_type"]="����";
  break;
  case "blade":
spe_skill["damage_type"]="����";
  break;
  case "strike":
spe_skill["damage_type"]="����";
  break;
  case "music":
  case "rube":
  case "piano":
spe_skill["damage_type"]="����";
  break;
 default:
spe_skill["damage_type"]="����";
  break;
 }

if(spe_skill_basename=="unarmed"
 || spe_skill_basename=="strike"
 || spe_skill_basename=="finger"
 ) {
spe_skill["damage"]=20+spe_skillnum*20;
spe_skill["parry"]=20+spe_skillnum*20;
 }
else if(spe_skill_basename=="sword"
 || spe_skill_basename=="blade"
 || spe_skill_basename=="rube"
 || spe_skill_basename=="music"
 || spe_skill_basename=="piano"
 || spe_skill_basename=="whip"
          ){
spe_skill["damage"]=20+spe_skillnum*20;
spe_skill["parry"]=20+spe_skillnum*20;
     }
else {
spe_skill["damage"]=20+spe_skillnum*20;
spe_skill["parry"]=20+spe_skillnum*20;
  }




spe_skill["lvl"]=spe_skillnum-1;

   
//here replace �� and С��� to ....
if(CHINESE_D->check_length(spe_skill["action"]) > 160)
{
 write(HIR"����̫����\n"NOR);
 return;
}

if(CHINESE_D->check_control(spe_skill["action"]))
{
 write(HIR"����书���������ÿ�����Ԫ��\n"NOR);
 return;
}

 spe_skill["action"]= replace_string(spe_skill["action"], "'"," ");
 spe_skill["action"]= replace_string(spe_skill["action"], "��","$N");
  spe_skill["action"]= replace_string(spe_skill["action"], "С���","$n");               
  spe_skill["action"]= replace_string(spe_skill["action"], "ĳ��λ","$l");              
if(spe_skill_basename=="sword"
         || spe_skill_basename=="blade"
         || spe_skill_basename=="rube"
         || spe_skill_basename=="music"
         || spe_skill_basename=="piano"
         || spe_skill_basename=="whip"
      ) 
  spe_skill["action"]= replace_string(spe_skill["action"], "����","$w");
  
 
action="\n([\n"
             +SHUANGYIN_HAO
           +"action"+SHUANGYIN_HAO
            +" :"
           +SHUANGYIN_HAO+
             spe_skill["action"]
            +SHUANGYIN_HAO
             +",\n"+
 SHUANGYIN_HAO+
  "force"+SHUANGYIN_HAO+" :"+ spe_skill["force"]+",\n"+
 SHUANGYIN_HAO+
  "damage"+SHUANGYIN_HAO+" :"+ spe_skill["damage"]+",\n"+
 SHUANGYIN_HAO+
  "damage_type" +SHUANGYIN_HAO+": "+SHUANGYIN_HAO+spe_skill["damage_type"]+
       SHUANGYIN_HAO+",\n"+
 SHUANGYIN_HAO+
 "lvl"+SHUANGYIN_HAO+" : "+spe_skill["lvl"]+",\n"+
 SHUANGYIN_HAO+
 "skill_name"+SHUANGYIN_HAO+" : "+SHUANGYIN_HAO+spe_skill["skill_name"]+
   SHUANGYIN_HAO 
   +"\n]),"
   +"\n });"
   +"\n// ZHAOSHI :"+spe_skillnum;


file=read_file(SKILL_D(spe_skill["skill_en_name"]));
if((int)file!=0)
    list = explode(file, "\n");

////////////////////////////////////////////////////////////////////
 //here replace the string SKILL_CH_NAME and SKILL_EN_NAME
if(spe_skill_basename=="unarmed" 
         || spe_skill_basename=="strike"
         || spe_skill_basename=="finger"
       )
    header2=read_file(SKILL_MODEL_UNARMED);
else if(spe_skill_basename=="sword" 
         || spe_skill_basename=="blade"
         || spe_skill_basename=="spear"
         || spe_skill_basename=="hammer"
         || spe_skill_basename=="rube"
         || spe_skill_basename=="music"
         || spe_skill_basename=="piano"
         || spe_skill_basename=="whip"
          )
    header2=read_file(SKILL_MODEL_WEAPON);
else 
    header2=read_file(SKILL_MODEL_DEFAULT);

list2 = explode(header2, "\n");
for(i=0;i < sizeof(list2);i++) {
//this is not the arg!!!
//spe_skill_name!=skill_en_name...
         list2[i]= replace_string(list2[i], "SKILL_EN_NAME", 
              SHUANGYIN_HAO+spe_skill_name+SHUANGYIN_HAO );
         list2[i]= replace_string(list2[i], "SKILL_CH_NAME", 
                SHUANGYIN_HAO+spe_skill["skill_ch_name"]+SHUANGYIN_HAO );
         list2[i]= replace_string(list2[i], "SKILL_BASE_NAME", 
              SHUANGYIN_HAO+spe_skill_basename+SHUANGYIN_HAO );
               }
//result contain the practice and exert information
for(i=0;i < sizeof(list2);i++) {
          result+=list2[i]+"\n";
        }
///////////////////////////////////////////////
//write("\nhere slslslls :"+spe_skillnum);
//now only a few be created,so the end is zhaoshi : 0
  if(spe_skillnum==1) {
      if(sscanf(list[sizeof(list)-1],"// ZHAOSHI :%d",before_skillnum)!=1){
             write("���ܳ����쳣�ˣ��粻�ܽ����֪ͨ��ʦ��\n");
            return;
           }
       }
  else {
  if(sscanf(list[sizeof(list)-1-SPE_PRA_LINES],"// ZHAOSHI :%d",before_skillnum)!=1){
             write("���ܳ����쳣�ˣ��粻�ܽ����֪ͨ��ʦ��\n");
                    return;
                  }
           }
        //this will be excuted if total get correctly
           {
              //remove the old action
                  if( before_skillnum==spe_skillnum){
         //  write("\nremove the old action\n");
                for(i=0;i < sizeof(list)-11-SPE_PRA_LINES;i++)
                     content+=list[i]+"\n";
                content+=action;
              rm(SKILL_D(spe_skill["skill_en_name"]));
              write_file(SKILL_D(spe_skill["skill_en_name"]),content);
               }
         else {
            //add a new action
//if it is a new create first
//then should be:
          rm(SKILL_D(spe_skill["skill_en_name"]));

          if(spe_skillnum!=1) {
                for(i=0;i < sizeof(list)-SPE_PRA_LINES-2;i++)
                     content+=list[i]+"\n";
            //      write("see list :"+sizeof(list));
                  content+="// ZHAOSHI :"+(string)before_skillnum
                               +"\n";
                  content+=action;
              write_file(SKILL_D(spe_skill["skill_en_name"]),content);
           //    write("\nadd a  action1\n");
                            }
          else if(spe_skillnum==1) {
                for(i=0;i < HEADER_END+3;i++)
                     content+=list[i]+"\n";
                  content+="// ZHAOSHI :"+(string)before_skillnum
                               +"\n";
                  content+=action;
              write_file(SKILL_D(spe_skill["skill_en_name"]),content);
          //     write("\nadd a  action2\n");
                            }
         
             }    
   //at last wirte the practice and other exert information
        write_file(SKILL_D(spe_skill["skill_en_name"]),"\n"+result);
     }
}
int check_legal_basename(string name)
{
int i;

for(i=0;i<sizeof(valid_types);i++) 
     if(valid_types[i]==name)
        return 1;

return 0;
}
int check_legal_id(string id)
{
 int i;

 i = strlen(id);

 if( (strlen(id) < 3) || (strlen(id) > 12 ) ) {
 write("����书���ű����� 3 �� 12 ��Ӣ����ĸ��\n");
 return 0;
 }
 while(i--)
 if( id[i]<'a' || id[i]>'z' ) {
 write("����书����ֻ����Ӣ����ĸ��\n");
                        return 0;
                }

        return 1;
}

int check_legal_name(string name)
{
 int i;
 i = strlen(name);
 if( (strlen(name) < 2) || (strlen(name) > 12 ) ) {
      write("�书���������Ʊ����� 1 �� 6 �������֡�\n");
 return 0;
 }
 while(i--) {
      if( name[i]<=' ' ) {
 write("����书�������ǲ����ÿ�����Ԫ��\n");
 return 0;
 }
  if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("����书������Ҫ�á����ġ�!\n");
                        return 0;
                }
        }

        if( member_array(name,banned_name)!=-1 ) {
                write("����书�������ƻ���������˵����š�\n");
                return 0;
        }
        return 1;

}

//file header of the skill for each file
//0:// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)
//1:// file owner id
//2:// file owner Chinese name
//3:// owner title
//4:// owner exp
//5:// owner gender
//6:// skill Chinese name
//7:// skill ���� of unarmed or sword or blade....etc
//8://
//9
//10
//11
//12
//13
//14 //reserved

int check_skillnum_exist(object me,string skill_en_name,int skill_num)
{
string file,*list;
string playername;
int total_zhaoshi_num;

// write("see the: "+skill_en_name+"\n");
//not reconmend programeing!@!!
file=read_file(SKILL_D(spe_skill["skill_en_name"]));
if(!file) {
        //have create another skill of unarmed,so can't create this
          if(me->query("skillmaxim/"+spe_skill_basename)!=0)
              return 0;
          else {
//             write("here be excuted???\n");
              return 1;
                 }
       }
else
    list = explode(file, "\n");
playername=geteuid(me);
if(list[1]!="// "+playername)
      return 0;
if(list[0]!="// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)")
           return 0;

//write("see the zhaoshi line:"+list[sizeof(list)-1-SPE_PRA_LINES]);

if(sscanf(list[sizeof(list)-1-SPE_PRA_LINES],"// ZHAOSHI :%d",total_zhaoshi_num)!=1)
           return 0;
//write("see total zhaoshi is:"+total_zhaoshi_num);
if(total_zhaoshi_num==0)
           return 0;
if(total_zhaoshi_num==skill_num)
          return skill_num;
else if(total_zhaoshi_num+1 == skill_num)
          return skill_num;
else 
 return 0;
}
 
//return num:
//error is 1,2,3,4,5
// 0 is the right return num
int check_owner_skill(object me,string skill_en_name)
{
	string file,*list;
	string playername;

	file=read_file(SKILL_D(skill_en_name));
	if(!file)
	{
        //have create another skill of unarmed,so can't create this
		if(me->query("skillmaxim/"+spe_skill_basename)!=0)
			return 1;
		else 
			return 0;
	}
	else
		list = explode(file, "\n");
	playername=geteuid(me);
//this have some problem of not a reconmend programeing... method
//just return 2.
	if(list[1]!="// "+playername)
		return 2;
	if(list[0]!="// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)")
		return 2;
	else
		return 0;
}

int check_action_name(string yn)
{
 int i;
 i = strlen(yn);

                if(CHINESE_D->check_control(yn))
{
 write("����书���������ÿ�����Ԫ��\n");
 return 0;
}
		if(CHINESE_D->check_length(yn) > 160)
{
 write("����书���������ÿ�����Ԫ��\n");
 return 0;
 }

 while(i--) {
      if( yn[i]<=' ' ) {
 write("����书���������ÿ�����Ԫ��\n");
 return 0;
 }
}
 return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ��creatskill �书�������� �书Ӣ������ �书�������� �ڼ���
���磺creatskill unarmed mytest �ҵ��Ʒ� 1
 
�������������Լ�����书��ָ����ž���ֵ��������������ʵ�ֵ���ʽ
Խ��Խ�࣬��ʽ������ҲԽ��Խ��
���������ʽ�������̶ȵķ�ʽ��ʹ������ר��ָ�
selfpractice,��practiceҲ���ԣ������ѶȻ�Ӵ�
selfthinking ������ selflearn �� learn

�������Լ�������ʽ�������Ѷ�Ҫ��Щ�����ֻ���޸ĵ�ǰ����ʽ������ǰ��
��ʽ�޷��Ķ����������Ҫ���ȹ滮��6-7�У��������޸ģ����⵽ʱ���޷�
�Ķ���ǰ�Ļ�����ʽ��

�������õĻ��������У�
 unarmed,
 sword,
 blade,
 staff,
 hammer,
 whip,
 finger,
 hand ,
 cuff ,
 claw ,
 strike,
ע��:
��ʽ��Ӣ�����ƺ��潫�����ϻ������ܵļ�����ʶ�����Ҫ������ã�һ��
��ʼ�������޷�����Ķ�Ӣ�����ơ�
��ʽ�����в�Ҫ��������ַ���
������ֻ�ܴ������ָ߼�����
�Ժ���ܻ�����changeskillnameָ������Ķ��Ѿ������õ��书��Ӣ��
���ƣ���Ŀǰ���ܡ�

��ʽ�����еģ�
С������㣬ĳ��λ�����������ձ��ԣ��������������Ը����ֲ�ͬ���ˡ�

��ʽ��������Ҫ���ж��Լ������״̬����д����Ҫ���������д��
��ʦ���������������Ĺ����粻���Ϲ涨������ɾ����
�����书����Ҫ2M���ϵľ���  

HELP
);
        return 1;
}
